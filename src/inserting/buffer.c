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
bool createGap(editor *user) {
    int start = user->xpos;
    int end = start + GAP_SIZE;
    int ypos = user->ypos;
    line *current = &user->file.lines[ypos];

    // make gap
    char *newData = realloc(current->data,
        current->capacity + GAP_SIZE
    );

    if (newData == NULL) return false;

    current->data = newData;
    current->capacity += GAP_SIZE;

    // copy current text over gap
    memmove(&current->data[end],
        &current->data[start],
        current->length - start
    );

    // for testing
    // for (int i = start; i < GAP_SIZE; i++) {
    //     current->data[i] = '\0';
    // }

    // save gap position
    user->gap.gapStart = start;
    user->gap.gapEnd = end;

    return true;

}