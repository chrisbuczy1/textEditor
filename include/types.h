// main struct to track user data in text editor
#ifndef TYPES_H
#define TYPES_H

typedef struct editor editor;
typedef struct line line;

typedef void (*func)(editor *);

struct line {
    int length;
    int capacity;
    char *data;
};

struct file {
    int length;
    FILE *file;
    char *name;
};

struct editor {
    int xpos;
    int ypos;
    char *buffer;
    char input;
    char mode;
    int bufferSize;
    int typeCount;
    int fileLines;
    func *cList;
    func *insertCList;
    struct termios settings;
    struct termios old;
    struct line currentLine;
    struct file file;
};

#endif