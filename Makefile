CC = gcc
CFLAGS = -Wall -Wextra

all: myeditor

myeditor: main.o commands.o modes.o settings.o
	$(CC) main.o commands.o modes.o settings.o -o myeditor

main.o: main.c commands.h modes.h settings.h types.h
	$(CC) $(CFLAGS) -c main.c

commands.o: commands.c commands.h types.h
	$(CC) $(CFLAGS) -c commands.c

modes.o: modes.c modes.h types.h settings.h
	$(CC) $(CFLAGS) -c modes.c

settings.o: settings.c settings.h types.h
	$(CC) $(CFLAGS) -c settings.c

clean:
	rm -f *.o myeditor