#include "screen.h"

void redrawLine(editor *user) {
    int xpos = user->xpos;
    moveHome(user);

    printf(user->file.lines[user->ypos].data);
    fflush(stdout);

    while (user->xpos < xpos) {
        printf(CURSOR_RIGHT);
        fflush(stdout);
        user->xpos++;
    }
}