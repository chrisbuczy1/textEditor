#include "cursorMovement.h"

void moveLeft(editor *user) {

    // regular left movement
    if (user->xpos > 0) {
        user->xpos--;
        printf(CURSOR_LEFT);
    }
    // left movement if user reaches end of line
    else {
        if (user->ypos > 0) {
            user->ypos--;
            printf(CURSOR_UP);
            while (user->xpos < user->file.lines[user->ypos].length) {
                printf(CURSOR_RIGHT);
                user->xpos++;
            }
        }
    }
}

void moveUp(editor *user) {
    if (user->ypos > 0) {

        // if line above is smaller
        if (user->xpos > user->file.lines[--user->ypos].length) {
            while (user->xpos > user->file.lines[user->ypos].length) {
                printf(CURSOR_LEFT);
                user->xpos--;
            }
        }

        // regular case
        printf(CURSOR_UP);
    }
}

void moveRight(editor *user) {
    // regular right movement
    if (user->xpos < user->file.lines[user->ypos].length) {
        user->xpos++;
        printf(CURSOR_RIGHT);
    } 

    // right movement if user reaches end of line
    else {
        if (user->ypos < user->file.numLines) {
            user->ypos++;
            printf(CURSOR_DOWN);
            while (user->xpos > 0) {
                user->xpos--;
                printf(CURSOR_LEFT);
            }
        }
    }
}

void moveDown(editor *user) {
    if (user->ypos < user->file.numLines) {

        // if line above is smaller
        if (user->xpos > user->file.lines[++user->ypos].length) {
            while (user->xpos > user->file.lines[user->ypos].length) {
                printf(CURSOR_LEFT);
                user->xpos--;
            }
        }

        // regular case
        printf(CURSOR_DOWN);
    }
}

void moveHome(editor *user) {
    if (user->xpos > 0) {
        while (user->xpos != 0) {
            user->xpos--;
            printf(CURSOR_LEFT);
        }
    }
}

void moveEnd(editor *user) {
    if (user->xpos < user->file.lines[user->ypos].length) {
        while (user->xpos != user->file.lines[user->ypos].length) {
            user->xpos++;
            printf(CURSOR_RIGHT);
        }
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