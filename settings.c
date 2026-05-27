#include "settings.h"

// canonical mode switches if you have to press enter to get input
void switchCanon(struct termios *settings) {
    settings->c_lflag ^= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, settings);
}

// echo switches if input is shown in terminal on type
void switchEcho(struct termios *settings) {
    settings->c_lflag ^= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, settings);
}

// restore old settings
void restoreSettings(struct termios *settings) {
    tcsetattr(STDIN_FILENO, TCSANOW, settings);
}

// get current settings
void getSettings(struct termios *old) {
    tcgetattr(STDIN_FILENO, old);
}