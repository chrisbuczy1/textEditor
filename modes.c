#include "modes.h"

void mode(editor *user) {
    
    // command of functions for each character
    setCommands(&user);
    
    // user presses escape to exit
    while (user->mode != ESC) {
        read(STDIN_FILENO, &mode, 1);
        if (user->cList[(int) user->mode] != 0) {
            user->cList[(int) user->mode](user);
        }
    } 
    return;
}



void save(FILE **file) {
    
}