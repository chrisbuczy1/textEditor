#include "commands.h"

void insertMode(void *s) {
    
    char *gBuffer = malloc(30);
    int count = 0;
    
    char input = 0;
    while (input != 27) {
        read(STDIN_FILENO, &input, 1);
        printf("%c", input);
        fflush(STDIN_FILENO);
    }
}

void insert(char **buffer, int size, int count, char input) {
    if ((count - 1) < size) {
        (*buffer)[count - 1] = input;
    } else {
        *buffer = realloc(*buffer, size * 2);
        (*buffer)[count - 1] = input;
    }
}

void delChar(char **buffer, int size, int count, char input) {

}

void setCommands(func *cList) {
    cList['i'] = insertMode;
    cList['I'] = insertMode;
}