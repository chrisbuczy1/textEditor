#include "normalMode.h"
#include "types.h"

// open file
void openFile(editor *user) {
    // open file
    FILE *edit = fopen(user->file.name, "a+");
    if (edit == NULL) {
        printf("failed to open file! ");
        return;
    }
    
    // display file
    clearScreen();
    size_t lineSize;
    char *line = NULL;
    while (getline(&line, &lineSize, edit) != -1) {
        printf("%s", line);
        fflush(stdout);
    }
    printf(HOME);
    fflush(stdout);
}

// get file name
void getFile(editor *user) {
    // get file name
    printf("enter a file name: ");
    size_t size;
    size_t len = getline(&user->file.name, &size, stdin);
    
    
    // get first string
    char *space = strchr(user->file.name, ' ');
    if (space == NULL) {
        if ((user->file.name)[len - 1] == '\n') {
            (user->file.name)[len - 1] = '\0';
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

void clearScreen() {
    printf("%s%s", CLEAR, HOME);
    fflush(stdout);
}