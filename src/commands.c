#include "commands.h"
#include "types.h"
#include <stdlib.h>
#include "insertCommands.h"

void insertMode(editor *user) {
    // while user doesn't input esc
    while (user->keySequence[0] != ESC) {
        int error = read(STDIN_FILENO, &(user->keySequence[0]), 1);
        
        // if user presses key that sends multiple bytes
        if (error != 1) {
            read(STDIN_FILENO, user->keySequence[0], 1);
            read(STDIN_FILENO, user->keySequence[1], 1);
            user->insertCList[ESC](user);
        } else {
            if (user->insertCList[user->keySequence[0]] != NULL) user->insertCList[user->keySequence[0]](user);
            else {
                printf("%c", user->keySequence[0]);
                fflush(stdout);
                user->xpos++;
            }
        }
        
        
    }

    user->keySequence[0] = '\0';
}

// function to insert characters to buffer
void insert(editor *user) {
    if (user->typeCount - 1 < user->bufferSize) {
        user->buffer[user->typeCount - 1] = user->keySequence[0];
    } else {
        user->bufferSize *= 2;
        user->buffer = realloc(user->buffer, user->bufferSize);
        user->buffer[user->typeCount - 1] = user->keySequence[0];
    }
    user->typeCount++;
}

void delChar(editor *user) {

}

/*
this function parses the bytes sent when user
clicks something other then regular keys,
keys like arrow keys, home, delete, etc.
*/ 
void parseKeySequence(editor *user) {
    // keep reading bytes until theres nothing to read
    while (read(STDIN_FILENO, user->keySequence[user->keySequenceLen], 1) != 1) {
        user->keySequenceLen++;
        printf("\n%d", user->keySequenceLen);
    }

    determineKey(user);
}

// determines key based of keySequence
void determineKey(editor *user) {
    if (user->keySequenceLen == 1) return ESC;

    if (user->keySequence[1] == '[') {
        puts("hi");
        
        switch (user->keySequence[2]) {
            case 'A':
                printf(CURSOR_UP);
                break;

            case 'B':
                return printf(CURSOR_DOWN);
                break;

            case 'C':
                printf(CURSOR_RIGHT);
                break;

            case 'D':
                printf(CURSOR_LEFT);
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

