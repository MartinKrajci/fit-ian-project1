# Binary Code Analysis
## Simplified `nm` tool

## Build
Use `make` command to build this project.

## Run
Tool needs to be run with exactly one paramater, which is path to the elf binary file.
```bash
$ ./proj1 elf_file
```

## Example
Example output for "Hello world" program written in C.
```bash
$ ./proj1 example 
    value       bind    type    name
00000000000000   0       4      /usr/lib/gcc/x86_64-redhat-linux/11/../../../../lib64/crt1.o
0000000040106f   0       0      .annobin_lto
0000000040106f   0       0      .annobin_lto_end
00000000401040   0       0      .annobin_lto.hot
00000000401040   0       0      .annobin_lto_end.hot
00000000401040   0       0      .annobin_lto.unlikely
00000000401040   0       0      .annobin_lto_end.unlikely
00000000401040   0       0      .annobin_lto.startup
00000000401040   0       0      .annobin_lto_end.startup
00000000401040   0       0      .annobin_lto.exit
00000000401040   0       0      .annobin_lto_end.exit
0000000040037c   0       1      __abi_tag
0000000040106f   0       0      .annobin_lto
0000000040106f   0       0      .annobin_lto_end
00000000401040   0       0      .annobin_lto.hot
00000000401040   0       0      .annobin_lto_end.hot
00000000401040   0       0      .annobin_lto.unlikely
00000000401040   0       0      .annobin_lto_end.unlikely
00000000401040   0       0      .annobin_lto.startup
00000000401040   0       0      .annobin_lto_end.startup
00000000401040   0       0      .annobin_lto.exit
00000000401040   0       0      .annobin_lto_end.exit
00000000401070   0       0      .annobin_lto
00000000401075   0       0      .annobin_lto_end
00000000401040   0       0      .annobin_lto.hot
00000000401040   0       0      .annobin_lto_end.hot
00000000401040   0       0      .annobin_lto.unlikely
00000000401040   0       0      .annobin_lto_end.unlikely
00000000401040   0       0      .annobin_lto.startup
00000000401040   0       0      .annobin_lto_end.startup
00000000401040   0       0      .annobin_lto.exit
00000000401040   0       0      .annobin_lto_end.exit
00000000401070   0       0      .annobin__dl_relocate_static_pie.start
00000000401075   0       0      .annobin__dl_relocate_static_pie.end
00000000000000   0       4      crtstuff.c
00000000401080   0       2      deregister_tm_clones
000000004010b0   0       2      register_tm_clones
000000004010f0   0       2      __do_global_dtors_aux
00000000404024   0       1      completed.0
00000000403e18   0       1      __do_global_dtors_aux_fini_array_entry
00000000401120   0       2      frame_dummy
00000000403e10   0       1      __frame_dummy_init_array_entry
00000000000000   0       4      example.c
00000000000000   0       4      crtstuff.c
00000000402144   0       1      __FRAME_END__
00000000403e18   0       0      __init_array_end
00000000403e20   0       1      _DYNAMIC
00000000403e10   0       0      __init_array_start
00000000402020   0       0      __GNU_EH_FRAME_HDR
00000000404000   0       1      _GLOBAL_OFFSET_TABLE_
000000004011b0   1       2      __libc_csu_fini
00000000404020   2       0      data_start
00000000404024   1       0      _edata
000000004011b8   1       2      _fini
00000000000000   1       2      printf@GLIBC_2.2.5
00000000000000   1       2      __libc_start_main@GLIBC_2.2.5
00000000404020   1       0      __data_start
00000000000000   2       0      __gmon_start__
00000000402008   1       1      __dso_handle
00000000402000   1       1      _IO_stdin_used
00000000401140   1       2      __libc_csu_init
00000000404028   1       0      _end
00000000401070   1       2      _dl_relocate_static_pie
00000000401040   1       2      _start
00000000404024   1       0      __bss_start
00000000401126   1       2      main
00000000404028   1       1      __TMC_END__
00000000401000   1       2      _init
```