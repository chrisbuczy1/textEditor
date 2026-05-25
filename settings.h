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

void switchCanon(struct termios *settings) {
    settings->c_lflag ^= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, settings);
}

void switchEcho(struct termios *settings) {
    settings->c_lflag ^= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, settings);
}

void restoreSettings(struct termios *settings) {
    tcsetattr(STDIN_FILENO, TCSANOW, settings);
}

void getSettings(struct termios *old) {
    tcgetattr(STDIN_FILENO, old);
}