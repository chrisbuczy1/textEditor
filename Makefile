all: myeditor clean

myeditor: main.o
	gcc main.o -o myeditor

main.o: main.c modes.h types.h settings.h commands.h
	gcc -c main.c -o main.o

clean:
	rm -f *.o