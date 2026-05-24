#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "modes.h"
#include "settings.h"

#define CLEAR "\033[2J"

void openFile(char *fName);
void getFile(char **fName);
void setSettings(struct termios *t);

int main() {
    char *fName = NULL;
    getFile(&fName);
    openFile(fName);
    
    // get settings
    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;

    // set settings
    newt.c_lflag &= ~ICANON;

    // save settings
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    char c;
    while (c != 25) {
        read(STDIN_FILENO, &c, 1);
        printf("%c\n", c);
        fflush(stdout);
    }
        
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
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