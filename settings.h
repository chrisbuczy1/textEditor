#include <termios.h>
#include <unistd.h>

struct termios oldt, newt;
tcgetattr(STDIN_FILENO, &oldt);
newt = oldt;

void switchCanon(struct termios *settings) {
    settings->c_iflag ^= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}