#include "buffer.h"

void doubleBuffer(void **buffer, size_t elementSize, size_t size) {
    *buffer = realloc(*buffer, (size * 2) * elementSize);
}