#include "normalMode.h"
#include "types.h"

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