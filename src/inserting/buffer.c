#include "buffer.h"

void doubleBuffer(editor *user) {
    user->buffer.buffer = realloc(user->buffer.buffer, (user->buffer.size) * 2);
    user->buffer.size *= 2;
}

void addToBuffer(editor *user) {
    if (user->buffer.typeCount == user->buffer.size) {
        doubleBuffer(user);
    }

    
}