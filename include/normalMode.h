#ifndef NORMALMODE_H
#define NORMALMODE_H

#include <stdbool.h>
#include "settings.h"
#include "commands.h"


void mode(editor *user);
void save(FILE **file);
void freeUser(editor *user);

#endif