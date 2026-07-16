#ifndef MODES_H
#define MODES_H

#include <stdbool.h>
#include "settings.h"
#include "commands.h"
#define ESC 27

void mode(editor *user);
void save(FILE **file);
void freeUser(editor *user);

#endif