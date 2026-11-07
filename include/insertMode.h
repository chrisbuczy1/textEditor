#ifndef INSERTMODE_H
#define INSERTMODE_H

#include "types.h"
#include <stdio.h>
#include <unistd.h>
#include "buffer.h"
#include "cursorMovement.h"
#include "screen.h"

void insertMode(editor *user);
void insertChar(editor *user);
void backspace(editor *user);
void insert(editor *user);
void delChar(editor *user);

#endif