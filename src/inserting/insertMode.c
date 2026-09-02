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
                insertChar(user);
            }
        }
        
        
    }

    user->keySequence[0] = '\0';
}

void insertChar(editor *user) {
    int ypos = user->ypos;
    int xpos = user->xpos;

    user->file.lines[ypos].data[xpos++] = user->keySequence[0];
}

void delChar(editor *user) {
    int ypos = user->ypos;
    int xpos = user->xpos;

    user->file.lines[ypos].data[xpos--] = NULL;
}