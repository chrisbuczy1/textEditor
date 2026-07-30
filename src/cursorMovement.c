#include "cursorMovement.h"

void moveLeft(editor *user) {
    if (user->xpos > 0) {
        user->xpos--;
        printf(CURSOR_LEFT);
        fflush(stdin);
    }
}

void moveUp(editor *user) {
    if (user->ypos > 0) {
        user->ypos--;
        printf(CURSOR_UP);
        fflush(stdin);
    }
}

void moveRight(editor *user) {
    if (user->xpos < user->currentLine.length) {
        user->ypos--;
        printf(CURSOR_UP);
        fflush(stdin);
    }
}

void moveDown(editor *user) {
    if (user->ypos < user->file.numLines) {
        user->ypos++;
        printf(CURSOR_DOWN);
        fflush(stdin);
    }
}

void pressedEsc(editor *user) {

}

void setInsertCommands(editor *user) {

    // arrow key movement
    user->insertCList[37] = moveLeft;
    user->insertCList[38] = moveUp;
    user->insertCList[39] = moveRight;
    user->insertCList[40] = moveDown;
    user->insertCList[ESC] = pressedEsc;
}