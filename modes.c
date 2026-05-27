#include "modes.h"

void mode(struct termios *settings) {
    
    // command of functions for each character
    func commands[256] = {0};
    setCommands(commands);
    char mode = 0;
    
    // user presses escape to exit
    while (mode != ESC) {
        read(STDIN_FILENO, &mode, 1);
        if (commands[(int) mode] != 0) {
            commands[(int) mode](settings);
        }
    } 
    return;
}



void save(FILE **file) {
    
}