// main struct to track user data in text editor
#ifndef TYPES_H
#define TYPES_H

#include <sys/select.h>

#define CLEAR "\033[2J"
#define HOME "\033[H"
#define ESC 27

typedef struct editor editor;
typedef struct line line;

typedef void (*func)(editor *);

struct line {
    int length;
    int capacity;
    char *data;
};

struct file {
    int numLines;
    line *lines;
    FILE *file;
    char *name;
};

struct editor {
    int xpos;
    int ypos;
    char *buffer;
    int bufferSize;
    int typeCount;
    int fileLines;
    char keySequence[6];
    int keySequenceLen;
    func *cList;
    func *insertCList;
    struct termios settings;
    struct termios old;
    struct line currentLine;
    struct file file;
    struct timeval timeout;
};

#endif