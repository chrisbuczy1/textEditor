#include <stdbool.h>
#include <unistd.h>
#include <termios.h>
#include "settings.h"



void mode();
void insertMode();
void save(FILE **file);

void mode() {
    char mode;
    read(STDIN_FILENO, &mode, 1);
    switch (mode) {
        case 'i':
        case 'I':
            insertMode();
            break;
    }
}

void insertMode() {
    switchEcho();
    
    char input;
    while (input != 27) {
        printf("hi\n");
        scanf("%c", &input);
    }
}

void save(FILE **file) {
    
}