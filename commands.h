#ifndef COMMANDS_H
#define COMMANDS_H

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "types.h"

#define ESC 27

void insertMode(editor *user);
void backspace(editor *user);
void insert(editor *user);
void setCommands(editor *user);
void delChar(char **buffer, int size, int count, char input);

#endif