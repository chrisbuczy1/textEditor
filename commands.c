#include "commands.h"
#include "types.h"

void insertMode(editor *user) {
    // while input does not equal esc
    user->input = 0;
    while (user->input != ESC) {
        read(STDIN_FILENO, &(user->input), 1);
        printf("%c", user->input);
        fflush(stdout);
    }
}

// function to insert characters
void insert(editor *user) {
    // if ((count - 1) < *size) {
    //     (*buffer)[count - 1] = input;
    // } else {
    //     *size *= 2;
    //     *buffer = realloc(*buffer, *size);
    //     (*buffer)[count - 1] = input;
    // }
    if (user->typeCount - 1 < user->bufferSize) {
        user->buffer[user->typeCount - 1] = user->input;
    } else {
        user->bufferSize *= 2;
        user->bufferSize = realloc(user->buffer, user->bufferSize);
        user->buffer[user->typeCount - 1] = user->input;
    }
    user->typeCount++;
}

void delChar(char **buffer, int size, int count, char input) {

}

void setCommands(editor *user) {
    user->cList['i'] = insertMode;
    user->cList['I'] = insertMode;
}