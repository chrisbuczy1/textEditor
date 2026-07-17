#include "modes.h"

void mode(editor *user) {
    
    // command of functions for each character
    setCommands(user);
    
    // user presses escape to exit
    // otherwise goes into user mode
    while (user->mode != ESC) {
        read(STDIN_FILENO, &(user->mode), 1);
        if (user->cList[user->mode] != 0) user->cList[user->mode](user);
    }
}

// free memory
void freeUser(editor *user) {
    free(user->cList);
    free(user->buffer);
}

void save(FILE **file) {
    
}