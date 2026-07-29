#include "modes.h"
#include "insertCommands.h"

void mode(editor *user) {
    
    // command of functions for each character
    setCommands(user);
    setInsertCommands(user);
    
    // user presses escape to exit
    // otherwise goes into user mode
    while (user->keySequence[0] != ESC && user->keySequenceLen != 1) {
        int keySequence = read(STDIN_FILENO, &(user->keySequence[0]), 1);

        // if the user clicked key that sends sequence
        if (user->keySequence[0] == ESC) {
            user->keySequenceLen++;
            user->cList[ESC](user);
        }

        // for regular commands
        else if (user->cList[user->keySequence[0]] != NULL) user->cList[user->keySequence[0]](user);
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