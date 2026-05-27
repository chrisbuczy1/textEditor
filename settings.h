// also including basic libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

void switchCanon(struct termios *settings);
void switchEcho(struct termios *settings);
void restoreSettings(struct termios *settings);
void getSettings(struct termios *old);

