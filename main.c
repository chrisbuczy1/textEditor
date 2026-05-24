#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modes.h"
#include "settings.h"

#define CLEAR "\033[2J"

void openFile(char *fName);
void getFile(char **fName);

int main() {
    char *fName = NULL;
    struct termios oldt, newt;
    
    // getFile(&fName);
    // openFile(fName);
    
    switchCanon();
    switchEcho();

    char c;
    while (c != 25) {
        mode();
    }
        
    restoreSettings();
    return 0;
}

void openFile(char *fName) {
    // open file
    FILE *edit = fopen(fName, "a+");
    if (edit == NULL) {
        printf("failed to open file! ");
        return;
    }
    
    // display file
    printf("%s", CLEAR);
    size_t lineSize;
    char *line = NULL;
    while (getline(&line, &lineSize, edit) != -1) {
        printf("%s", line);
    }
    printf("\033[H");
}

void getFile(char **fName) {
    // get file name
    printf("enter a file name: ");
    size_t size;
    size_t len = getline(fName, &size, stdin);
    
    
    // get first string
    char *space = strchr(*fName, ' ');
    if (space == NULL) {
        if ((*fName)[len - 1] == '\n') {
            (*fName)[len - 1] = '\0';
        }
        return;
    }
    *space = '\0';
}