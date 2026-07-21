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