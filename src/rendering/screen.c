#include "screen.h"

void redrawLine(editor *user) {
    int xpos = user->xpos;
    line current = user->file.lines[user->ypos];

    CLEAR_LINE;
    moveHome(user);

    for (int i = 0; i < user->gap.gapStart; i++) {
        printf("%c", current.data[i]);
        xpos++;
    }

    for (int i = user->gap.gapEnd; i < current.capacity; i++) {
        printf("%c", current.data[i]);
        xpos++;
    }

    // printf("%d userxpos", user->xpos);
    while (xpos > user->xpos) {
        printf(CURSOR_LEFT);
        xpos--;
    }

    fflush(stdout);
}