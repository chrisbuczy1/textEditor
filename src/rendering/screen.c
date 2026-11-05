#include "screen.h"

void redrawLine(editor *user) {
    int xpos = user->xpos;
    line current = user->file.lines[user->ypos];

    CLEAR_LINE;
    moveHome(user);

    for (int i = 0; i < user->gap.gapStart; i++) {
        putchar(current.data[xpos]);
        moveRight(user);
    }

    for (int i = user->gap.gapEnd; i < current.capacity; i++) {
        putchar(current.data[xpos]);
        moveRight(user);
    }
//     int xpos = user->xpos;
//     line current = user->file.lines[user->ypos];

//     CLEAR_LINE;
//     moveHome(user);

//     printf("%s", user->file.lines[user->ypos].data);
//     printf(CURSOR_UP);

//     while (user->xpos < xpos) {
//         printf(CURSOR_RIGHT);
//         user->xpos++;
//     }

    fflush(stdout);
}