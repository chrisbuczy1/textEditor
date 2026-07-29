#include "normalMode.h"

int main() {
    printf(CLEAR);
    printf(HOME);
    fflush(stdout);
    // set beginning settings
    char *fName = NULL;
    struct termios oldt, newt;
    editor user = {
        .xpos = 0,
        .ypos = 0,
        .buffer = calloc(30, 1),
        .bufferSize = 30,
        .typeCount = 0,
        .fileLines = 0,
        .cList = calloc(256, sizeof(func)),
        .insertCList = calloc(256, sizeof(func)),
        .settings = newt,
        .old = oldt,
        .currentLine = {
            .length = 0,
            .capacity = 30,
            .data = NULL
        },
        .file = NULL,
        .keySequence = {0},
        .keySequenceLen = 0,
        .timeout = {
            .tv_sec = 0,
            .tv_usec = 10000
        }
    };
    getSettings(&user);
    user.settings = user.old;
    
    // getFile(&fName);
    // openFile(fName);
    switchCanon(&user);
    switchEcho(&user);
    
    // main loop
    mode(&user);
    
    // set old settings
    restoreSettings(&user);

    // exit
    freeUser(&user);
    return 0;
}

// free memory
void freeUser(editor *user) {
    free(user->cList);
    free(user->buffer);
    free(user->insertCList);
}