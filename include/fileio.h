#ifndef FILEIO_H
#define FILEIO_H

#include "types.h"
#include <stdio.h>

void openFile(editor *user);
void getFile(editor *user);
long getFileSize(FILE *file);
void clearScreen();

#endif