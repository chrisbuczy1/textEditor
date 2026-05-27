#include <stdbool.h>
#include "settings.h"
#include "commands.h"
#define ESC 27

void mode(struct termios *settings);
void save(FILE **file);

