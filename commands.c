#include "commands.h"
#include "types.h"

void insertMode(void *s) {
    
    // make buffer
    char *gBuffer = malloc(30);
    int count = 0;
    
    // while input does not equal esc
    char input = 0;
    while (input != ESC) {
        read(STDIN_FILENO, &input, 1);
        printf("%c", input);
        fflush(stdout);
    }
}

// function to insert characters
void insert(char **buffer, int *size, int count, char input) {
    if ((count - 1) < *size) {
        (*buffer)[count - 1] = input;
    } else {
        *size *= 2;
        *buffer = realloc(*buffer, *size);
        (*buffer)[count - 1] = input;
    }
    count++;
}

void delChar(char **buffer, int size, int count, char input) {

}

void setCommands(func *cList) {
    cList['i'] = insertMode;
    cList['I'] = insertMode;
}