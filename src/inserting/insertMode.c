#include "insertMode.h"
#include "buffer.h"

void insertMode(editor *user) {
    // while user doesn't input esc
    while (user->keySequence[0] != ESC) {
        int error = read(STDIN_FILENO, &(user->keySequence[0]), 1);
        
        // if user presses key that sends multiple bytes
        if (error != 1) {
            read(STDIN_FILENO, user->keySequence[0], 1);
            read(STDIN_FILENO, user->keySequence[1], 1);
            user->insertCList[ESC](user);
        }

        // otherwise, insert the character
        else {
            if (user->insertCList[user->keySequence[0]] != NULL) user->insertCList[user->keySequence[0]](user);
            else {
                addToBuffer(user);
            }
        }
        
        
    }

    user->keySequence[0] = '\0';
}

// function to insert characters to buffer
void insert(editor *user) {
    if (user->buffer.typeCount - 1 < user->buffer.size) {
        user->buffer.buffer[user->buffer.typeCount - 1] = user->keySequence[0];
    } else {
        user->buffer.size *= 2;
        user->buffer.buffer = realloc(user->buffer.buffer, user->buffer.size);
        user->buffer.buffer[user->buffer.typeCount - 1] = user->keySequence[0];
    }
    user->buffer.typeCount++;
}

void delChar(editor *user) {

}