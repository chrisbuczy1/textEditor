#ifndef SETTINGS_H
#define SETTINGS_H

// also including basic libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "types.h"

void switchCanon(editor *user);
void switchEcho(editor *user);
void restoreSettings(editor *user);
void getSettings(editor *user);

#endif