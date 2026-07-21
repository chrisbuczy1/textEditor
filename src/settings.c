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
    tcsetattr(STDIN_FILENO, TCSANOW, &(user->old));
}
/*
read() waits for a byte wether there is one or not
this function sets a time interval where read() will stop looking for bytes after it
*/ 
int readyToRead(editor *user) {
    
    // set FD_SET
    fd_set set;
    FD_ZERO(&set);
    FD_SET(STDIN_FILENO, &set);

    // return 1 if stdin is ready to be read
    return select(STDIN_FILENO + 1,
    &set,
    NULL,
    NULL,
    &user->timeout);
}

// get current settings
void getSettings(editor *user) {
    tcgetattr(STDIN_FILENO, &(user->old));
}