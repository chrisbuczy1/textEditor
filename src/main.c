#include "normalMode.h"
#include "fileio.h"

int main() {
    
    write(STDOUT_FILENO, CLEAR, 4);
    write(STDOUT_FILENO, HOME, 3);
    fflush(stdout);

    // set beginning settings
    struct termios oldt, newt;
    editor user = {
        .xpos = 0,
        .ypos = 0,
        .buffer = {
            .buffer = calloc(30, 1),
            .size = 29,
            .typeCount = 0
        },
        .cList = calloc(256, sizeof(func)),
        .insertCList = calloc(256, sizeof(func)),
        .settings = newt,
        .old = oldt,
        .currentLine = {
            .length = 0,
            .capacity = 30,
            .data = NULL
        },
        .file = {
            .numLines = NULL,
            .lines = calloc(sizeof(line), 100),
            .capacity = 100,
            .file = NULL,
            .name = NULL
        },
        .keySequence = {0},
        .keySequenceLen = 0,
        .timeout = {
            .tv_sec = 0,
            .tv_usec = 10000
        }
    };

    // file stuff
    getFile(&user);
    openFile(&user);

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
    free(user->buffer.buffer);
    free(user->file.lines);
    free(user->file.name);
    free(user->cList);
    free(user->insertCList);
    free(user->insertCList);
}