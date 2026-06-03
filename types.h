// main struct to track user data in text editor
#ifndef TYPES_H
#define TYPES_H

typedef void (*func)(struct editor *);

typedef struct editor {
    int xpos;
    int ypos;
    char *buffer;
    char input;
    char mode;
    int bufferSize;
    int typeCount;
    func *cList;
    struct termios settings;
    struct termios old;
} editor;

#endif