#ifndef COMMANDS_H
#define COMMANDS_H

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "types.h"

#define ESC 27
#define CURSOR_UP "\033[1A"
#define CURSOR_DOWN "\033[1B"
#define CURSOR_RIGHT "\033[1C"
#define CURSOR_LEFT "\033[1D"

void insertMode(editor *user);
void backspace(editor *user);
void insert(editor *user);
void setCommands(editor *user);
void delChar(char **buffer, int size, int count, char input);

#endif