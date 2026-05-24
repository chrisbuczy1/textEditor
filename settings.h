#include <termios.h>
#include <unistd.h>

struct termios oldt, newt;
tcgetattr(STDIN_FILENO, &oldt);
newt = oldt;

void switchCanon() {
    newt.c_iflag ^= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void switchEcho() {
    newt.c_iflag ^= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}