#include "buffer.h"

// doubles buffer size
// void doubleBuffer(editor *user) {
//     user->buffer.buffer = realloc(user->buffer.buffer, (user->buffer.size) * 2);
//     user->buffer.size *= 2;
// }

// adds typed character to buffer
// void addToBuffer(editor *user) {
//     if (user->buffer.typeCount == user->buffer.size) {
//         doubleBuffer(user);
//     }

//     user->buffer.buffer[user->buffer.typeCount++] = user->keySequence[0];
//     user->xpos++;
// }

// adds character from buffer to line
void createGap(editor *user) {
    int start = user->xpos;
    int end = start + GAP_SIZE;
    int ypos = user->ypos;
    line *current = &user->file.lines[ypos];

    // save gap position
    user->gap.gapStart = start;
    user->gap.gapEnd = end;

    printf("Hi");

    // make gap
    current->data = realloc(user->file.lines[ypos].data,
        user->file.lines[ypos].length + GAP_SIZE
    );
    current->capacity += GAP_SIZE;

    printf("Bye");

    // copy current text over gap
    memmove(&current->data[start + GAP_SIZE],
        &current->data[start],
        current->length - start
    );

}