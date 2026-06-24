// main struct to track user data in text editor
#ifndef TYPES_H
#define TYPES_H

typedef struct editor editor;

typedef void (*func)(editor *);

struct editor {
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
};

#endif