#include "modes.h"

#define CLEAR "\033[2J"
#define HOME "\033[H"

void openFile(char *fName);
void getFile(char **fName);

int main() {
    printf(CLEAR);
    printf(HOME);
    fflush(stdout);

    // set beginning settings
    char *fName = NULL;
    struct termios oldt, newt;
    getSettings(&oldt);
    newt = oldt;
    
    // getFile(&fName);
    // openFile(fName);
    switchCanon(&newt);
    switchEcho(&newt);
    
    // main loop
    char **fileText;
    mode(&newt);
    
    // set old settings
    restoreSettings(&oldt);
    return 0;
}

// open file
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
    printf(HOME);
}

// get file name
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

// get amount of chars in file
long getFileSize(FILE *file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    
    return size;
}