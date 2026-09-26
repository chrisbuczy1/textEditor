#include "insertMode.h"

void insertMode(editor *user) {
    // while user doesn't input esc
    while (user->keySequence[0] != ESC && user->keySequenceLen != 1) {
        
        // if user presses key that sends multiple bytes
        int keySequence = read(STDIN_FILENO, &(user->keySequence[0]), 1);

        if (user->keySequence[0] == ESC) {
            user->keySequenceLen++;
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
    line *current = &user->file.lines[ypos];

    if (current->length >= current->capacity) createGap(user);

    current->data[xpos++] = user->keySequence[0];
    printf(CURSOR_RIGHT);
    current->length++;
    
    redrawLine(user);
}

void delChar(editor *user) {
    int ypos = user->ypos;
    int xpos = user->xpos;
    line *current = &user->file.lines[ypos];

    if (current->length <= 1) {
        user->file.lines[ypos].data[xpos--] = NULL;
        current->capacity++;
        current->length++;
    }
    

    redrawLine(user);
}

void setInsertCommands(editor *user) {

    // arrow key movement
    user->insertCList[37] = moveLeft;
    user->insertCList[38] = moveUp;
    user->insertCList[39] = moveRight;
    user->insertCList[40] = moveDown;
    user->insertCList[ESC] = parseKeySequence;
}