/*
*   Name: Martin Krajci
*   Login: xkrajc21
*   Subject: IAN
*   Project number: 1
*/

/*
*   Program description:
*   Program is taking ELF file name as input. After successful
*   opening, ELF file is mapped in the memory. From the ELF header 
*   is obtained info about section header table and string header
*   table. From all the sections is taken info about symbol table
*   and string table. Symbol table contains information about all
*   the symbols in given ELF file and also contains index to the
*   string table, which is needed for symbols names. Name, type and
*   binding of symbols is printed on standard output, which simulates
*   linux "nm" command.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <elf.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

// Get offsets of symbol and string table.
void get_offsets(Elf64_Ehdr *header, void *elfFile, Elf64_Sym **sym, char **str, int *symCount)
{
    Elf64_Shdr *sectTable;
    char *strHeader;
    int sectOff;
    int sectCount;
    int symOff;
    int symSize;
    int strOff;
    int strHeaderOff;
    int strHeaderIndex;

    //Check if section header table exists.
    sectOff = (int) (*header).e_shoff;
    if(sectOff == 0)
    {
        fprintf(stderr, "No section header found!\n");
        exit(EXIT_FAILURE);
    }

    sectCount = (*header).e_shnum;
    
    //Mapping section table
    sectTable = (Elf64_Shdr *) (elfFile + sectOff);

    strHeaderIndex = (*header).e_shstrndx;

    //Searching for symbol table and string header table in section table.
    for(int i = 0; i < sectCount; i++)
    {
        if (sectTable[i].sh_type == SHT_SYMTAB)
        {
            symOff = sectTable[i].sh_offset;
            symSize = sectTable[i].sh_size;
        }

        if (sectTable[i].sh_type == SHT_STRTAB && strHeaderIndex == i)
        {
            strHeaderOff = sectTable[i].sh_offset;
            //strHeaderSize = sectTable[i].sh_size;
        }
    }

    //Pointer to string header table.
    strHeader = (char *) elfFile + strHeaderOff;

    //Searching for string table.
    for(int i = 0; i < sectCount; i++)
    {
        if (sectTable[i].sh_type == SHT_STRTAB && strcmp(&(strHeader[sectTable[i].sh_name]), ".strtab") == 0)
        {
            strOff = sectTable[i].sh_offset;
            //strSize = sectTable[i].sh_size;
        }
    }

    //Pointer to symbol table.
    *symCount = symSize / sizeof(Elf64_Sym);
    *sym = (Elf64_Sym *) (elfFile + symOff);

    //Pointer to string table.
    *str = (char *) elfFile + strOff;
}

// Open and map the elf file to the memory.
void *mapElf(char *elfName)
{
    int elfFD, elfFDTmp;
    int elfSize;
    void *elfPointer;

    elfFD = elfFDTmp = open(elfName, O_RDONLY);
    if(elfFD < 0)
    {
        fprintf(stderr, "Could not open file \"%s\"!\n", elfName);
        exit(EXIT_FAILURE);
    }

    elfSize = lseek(elfFDTmp, 0L, SEEK_END);

    elfPointer = mmap(NULL, elfSize, PROT_READ, MAP_PRIVATE, elfFD, 0);
    close(elfFD);
    if(elfPointer == MAP_FAILED)
    {
        fprintf(stderr, "Error while mapping ELF file in memory! %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    return (elfPointer);
}

// Print symbols of ELF file to stdout, simulating "nm" command. 
void printResult(int *symCount, Elf64_Sym *symbolTable, char *stringTable)
{
    printf("    value\tbind\ttype\tname\n");
    for (int i = 0; i < *symCount; ++i)
    {
        int stringTableIndex = symbolTable[i].st_name;
        if (stringTableIndex != 0)
        {
            printf("%014x\t%2d\t%2d\t%s\n", (int) symbolTable[i].st_value, ELF64_ST_BIND(symbolTable[i].st_info), ELF64_ST_TYPE(symbolTable[i].st_info), &(stringTable[stringTableIndex]));
        }
    }
    return;
}

int main(int argc, char **argv)
{
    Elf64_Ehdr *header;
    Elf64_Sym *sym = NULL;
    char *str = NULL;
    void *elfFile;
    int symCount;

    //Controling number of arguments.
    if (argc != 2)
    {
        fprintf(stderr, "Expecting name of ELF file as argument!\n");
        return 1;
    }

    elfFile = mapElf(argv[1]);
    header = (Elf64_Ehdr*) elfFile;

    get_offsets(header, elfFile, &sym, &str, &symCount);

    printResult(&symCount, sym, str);

    return 0;
}