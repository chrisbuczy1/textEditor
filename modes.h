#include <stdbool.h>
#include "settings.h"
#include "commands.h"


void mode(struct termios *settings);
void save(FILE **file);

void mode(struct termios *settings) {
    func commands[256] = {0};
    setCommands(commands);
    char mode = 0;
    
    while (mode != 27) {
        read(STDIN_FILENO, &mode, 1);
        if (commands[(int) mode] != 0) {
            commands[(int) mode](settings);
        }
    } 
    return;
}



void save(FILE **file) {
    
}