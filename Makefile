CC = gcc
FLAGS = -Wall
PROGNAME = proj1

all: $(PROGNAME)

$(PROGNAME): $(PROGNAME).c
	$(CC) $(FLAGS) $(PROGNAME).c -o $(PROGNAME)

clean:
	rm $(PROGNAME)
