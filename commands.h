#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "types.h"

#define ESC 27

typedef void (*func)(void *);

void insertMode(void *s);
void backspace(void *s);
void insert(char **buffer, int *size, int count, char input);
void delChar(char **buffer, int size, int count, char input);

