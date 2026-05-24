myeditor: main.o
	gcc main.o -o myeditor

main.o: main.c modes.h types.h settings.h
	gcc -c main.c -o main.o
	clean

clean:
	rm -f *.o myeditor