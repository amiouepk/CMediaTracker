#ifndef FILE_HELP_H
#define FILE_HELP_H
#include <stdio.h>
#include <stdlib.h>


int ifFileExists(const char* name);

void createFile(const char* name, FILE** fp);



#endif