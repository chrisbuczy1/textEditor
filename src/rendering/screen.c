#include "screen.h"

void redrawLine(editor *user) {
    int xpos = user->xpos;
    line current = user->file.lines[user->ypos];

    CLEAR_LINE;
    moveHome(user);

    for (int i = 0; i < user->gap.gapStart; i++) {
        printf("%c", current.data[i]);
        user->xpos++;
    }

    for (int i = user->gap.gapEnd; i < current.capacity; i++) {
        printf("%c", current.data[i]);
        user->xpos++;
    }

    moveHome(user);
    while (user->xpos < xpos) {
        printf(CURSOR_RIGHT);
        user->xpos++;
    }

    fflush(stdout);
}