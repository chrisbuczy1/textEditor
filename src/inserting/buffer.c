#include "buffer.h"

void doubleBuffer(editor *user) {
    user->buffer.buffer = realloc(user->buffer.buffer, (user->buffer.bufferSize) * 2);
    user->buffer.bufferSize *= 2;
}

void addToBuffer(editor *user) {
    if (user->buffer.typeCount == user->buffer.bufferSize) {
        doubleBuffer(user);
    }

    
}