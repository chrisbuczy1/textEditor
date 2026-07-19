#include "commands.h"
#include "types.h"
#include <stdlib.h>
#include "insertCommands.h"

void insertMode(editor *user) {
    // while user doesn't input esc
    while (user->input != ESC) {
        int error = read(STDIN_FILENO, &(user->input), 1);
        
        // if user presses key that sends multiple bytes
        if (error != 1) {
            read(STDIN_FILENO, user->keySequence[0], 1);
            read(STDIN_FILENO, user->keySequence[1], 1);
            user->insertCList[ESC](user);
        } else {
            if (user->insertCList[user->input] != 0) user->insertCList[user->input](user);
            else {
                printf("%c", user->input);
                fflush(stdout);
                user->xpos++;
            }
        }
        
        
    }

    user->input = '\0';
}

// function to insert characters to buffer
void insert(editor *user) {
    if (user->typeCount - 1 < user->bufferSize) {
        user->buffer[user->typeCount - 1] = user->input;
    } else {
        user->bufferSize *= 2;
        user->buffer = realloc(user->buffer, user->bufferSize);
        user->buffer[user->typeCount - 1] = user->input;
    }
    user->typeCount++;
}

void delChar(char **buffer, int size, int count, char input) {

}

/*
this function parses the bytes sent when user
clicks something other then regular keys,
keys like arrow keys, home, delete, etc.
*/ 
void parseKeySequence(editor *user) {
    // keep reading bytes until theres nothing to read
    while (read(STDIN_FILENO, user->keySequence[user->keySequenceLen], 1) == 1) user->keySequenceLen++;

    determineKey(user);
}

// determines key based of keySequence
void determineKey(user) {
    
}

// set each character to a command in normal mode
void setCommands(editor *user) {
    user->cList['i'] = insertMode;
    user->cList['I'] = insertMode;
    user->cList[ESC] = parseKeySequence;
}

