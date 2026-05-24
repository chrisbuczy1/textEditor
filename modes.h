#include <stdbool.h>
#include <unistd.h>
#include <termios.h>



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
    char input;
    scanf("%c", &input);
    while (input != '^Y') {
        printf("hi\n");
        scanf("%c", &input);
    }
}

void save(FILE **file) {
    
}