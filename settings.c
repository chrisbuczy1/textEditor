#include "settings.h"

// canonical mode switches if you have to press enter to get input
void switchCanon(editor *user) {
    user->settings.c_lflag ^= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &(user->settings));
}

// echo switches if input is shown in terminal on type
void switchEcho(editor *user) {
    user->settings.c_lflag ^= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &(user->settings));
}

// restore old settings
void restoreSettings(editor *user) {
    tcsetattr(STDIN_FILENO, TCSANOW, &(user->settings));
}

// get current settings
void getSettings(editor *user) {
    tcgetattr(STDIN_FILENO, &(user->old));
}