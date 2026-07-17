#include "modes.h"
#include "insertCommands.h"

void mode(editor *user) {
    
    // command of functions for each character
    setCommands(user);
    setInsertCommands(user);
    
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
    free(user->insertCList);
}

void save(FILE **file) {
    
}