#include "commands.h"
#include "types.h"
#include <stdlib.h>
#include "cursorMovement.h"

/*
this function parses the bytes sent when user
clicks something other then regular keys,
keys like arrow keys, home, delete, etc.
*/ 
void parseKeySequence(editor *user) {
    // keep reading bytes until theres nothing to read
    while (user->keySequenceLen < sizeof(user->keySequence)) {

        if (readyToRead(user)) {
            read(STDIN_FILENO, &user->keySequence[user->keySequenceLen], 1);
            user->keySequenceLen++;
        }

        else break;
        
    }

    determineKey(user);
}

// determines key based of keySequence
void determineKey(editor *user) {

    // if ESC clicked, exit function and exit mode
    if (user->keySequenceLen == 1) return;


    // otherwise, move cursor
    if (user->keySequence[1] == '[') {
        
        switch (user->keySequence[2]) {
            case 'A':
                moveUp(user);
                fflush(stdout);
                break;

            case 'B':
                moveDown(user);
                fflush(stdout);
                break;

            case 'C':
                moveRight(user);
                fflush(stdout);
                break;

            case 'D':
                moveLeft(user);
                fflush(stdout);
                break;
            
            case 'H':
                moveHome(user);
                fflush(stdout);
                break;
            
            case 'F':
                moveEnd(user);
                fflush(stdout);
                break;
        }
    }

    // reset keySequence and keySequenceLen
    memset(user->keySequence, 0, sizeof(user->keySequence));
    user->keySequenceLen = 0;

}

// set each character to a command in normal mode
void setCommands(editor *user) {
    user->cList['i'] = insertMode;
    user->cList['I'] = insertMode;
    user->cList[ESC] = parseKeySequence;
}

