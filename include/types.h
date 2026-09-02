// main struct to track user data in text editor
#ifndef TYPES_H
#define TYPES_H

#include <sys/select.h>
#include <termios.h>
#include <stdio.h>

#define CLEAR "\033[2J"
#define HOME "\033[H"
#define ESC 27
#define GAP_SIZE 64

typedef struct editor editor;
typedef struct line line;
typedef struct gap gap;

typedef void (*func)(editor *);

struct line {
    int length;
    int capacity;
    char *data;
};

struct file {
    int numLines;
    line *lines;
    int capacity;
    FILE *file;
    char *name;
};

struct gap {
    int gapStart;
    int gapEnd;
};

struct editor {
    int xpos;
    int ypos;
    struct gap gap;
    char keySequence[6];
    int keySequenceLen;
    func *cList;
    func *insertCList;
    struct termios settings;
    struct termios old;
    struct file file;
    struct timeval timeout;
};

#endif