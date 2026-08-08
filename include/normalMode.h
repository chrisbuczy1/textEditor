#ifndef NORMALMODE_H
#define NORMALMODE_H

#include <stdbool.h>
#include "settings.h"
#include "commands.h"


void mode(editor *user);
void save(editor *user);
void freeUser(editor *user);

#endif