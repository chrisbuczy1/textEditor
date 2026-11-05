#ifndef RENDERING_H
#define RENDERING_H

#include "types.h"
#include "cursorMovement.h"

#define CLEAR_LINE printf("\033[2k")

void redrawLine(editor *user);

#endif