#ifndef CURSORMOVEMENT_H
#define CURSORMOVEMENT_H

#include "commands.h"

#define CURSOR_UP "\033[1A"
#define CURSOR_DOWN "\033[1B"
#define CURSOR_RIGHT "\033[1C"
#define CURSOR_LEFT "\033[1D"

void setInsertCommands(editor *user);
void moveUp(editor *user);
void moveRight(editor *user);
void moveLeft(editor *user);
void moveDown(editor *user);
void pressedEsc(editor *user);

#endif