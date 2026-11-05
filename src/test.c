#include "cursorMovement.h"

void testPrint(char *string) {
    for (int i = 0; i < 10; i++) printf(CURSOR_DOWN);
    printf("%s", string);
    fflush(stdout);
    for (int i = 0; i < 10; i++) printf(CURSOR_UP);
}