#ifndef INSERTMODE_H
#define INSERTMODE_H

#include "types.h"
#include <stdio.h>
#include <unistd.h>
#include "buffer.h"
#include "cursorMovement.h"

void insertMode(editor *user);
void backspace(editor *user);
void insert(editor *user);

#endif