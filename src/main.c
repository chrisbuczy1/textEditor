#include "modes.h"
#include "main.h"

int main() {
    printf(CLEAR);
    printf(HOME);
    fflush(stdout);
    // set beginning settings
    char *fName = NULL;
    struct termios oldt, newt;
    editor user = {
        .xpos = 0,
        .ypos = 0,
        .buffer = calloc(30, 1),
        .bufferSize = 30,
        .typeCount = 0,
        .fileLines = 0,
        .cList = calloc(256, sizeof(func)),
        .insertCList = calloc(256, sizeof(func)),
        .settings = newt,
        .old = oldt,
        .currentLine = {
            .length = 0,
            .capacity = 30,
            .data = NULL
        },
        .file = NULL,
        .keySequence = {0},
        .keySequenceLen = 0,
        .timeout = {
            .tv_sec = 0,
            .tv_usec = 10000
        }
    };
    getSettings(&user);
    user.settings = user.old;
    
    // getFile(&fName);
    // openFile(fName);
    switchCanon(&user);
    switchEcho(&user);
    
    // main loop
    mode(&user);
    
    // set old settings
    restoreSettings(&user);

    // exit
    freeUser(&user);
    return 0;
}

// open file
// void openFile(char *fName) {
//     // open file
//     FILE *edit = fopen(fName, "a+");
//     if (edit == NULL) {
//         printf("failed to open file! ");
//         return;
//     }
    
//     // display file
//     printf("%s", CLEAR);
//     size_t lineSize;
//     char *line = NULL;
//     while (getline(&line, &lineSize, edit) != -1) {
//         printf("%s", line);
//     }
//     printf(HOME);
// }

// // get file name
// void getFile(char **fName) {
//     // get file name
//     printf("enter a file name: ");
//     size_t size;
//     size_t len = getline(fName, &size, stdin);
    
    
//     // get first string
//     char *space = strchr(*fName, ' ');
//     if (space == NULL) {
//         if ((*fName)[len - 1] == '\n') {
//             (*fName)[len - 1] = '\0';
//         }
//         return;
//     }
//     *space = '\0';
// }

// // get amount of chars in file
// long getFileSize(FILE *file) {
//     fseek(file, 0, SEEK_END);
//     long size = ftell(file);
//     rewind(file);
    
//     return size;
// }