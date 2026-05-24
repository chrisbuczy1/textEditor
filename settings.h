#include <termios.h>
#include <unistd.h>

void switchCanon(struct termios *settings);
void switchEcho(struct termios *settings);
void restoreSettings(struct termios *settings);

void switchCanon(struct termios *settings) {
    settings->c_iflag ^= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, settings);
}

void switchEcho(struct termios *settings) {
    settings->c_iflag ^= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, settings);
}

void restoreSettings(struct termios *settings) {
    tcsetattr(STDIN_FILENO, TCSANOW, settings);
}

void getSettings(struct termios *old, struct termios *new) {
    tcgetattr(STDIN_FILENO, )
}