#ifndef COMMANDS_H
#define COMMANDS_H

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "types.h"
#include <string.h>



typedef enum {
    ARROW_UP = 1000,
    ARROW_DOWN,
    ARROW_RIGHT,
    ARROW_LEFT
} Key;

void insertMode(editor *user);
void backspace(editor *user);
void insert(editor *user);
void setCommands(editor *user);
void delChar(editor *user);
void parseKeySequence(editor *user);
void determineKey(editor *user);

#endif