#ifndef FILE_HELP_H
#define FILE_HELP_H


int ifFileExists(const char* name);

void createFile(const char* name, FILE* fp);

char* filenameFilter(char* filename_raw);





#endif