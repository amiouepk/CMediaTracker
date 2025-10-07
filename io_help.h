#ifndef IO_HELP_H
#define IO_HELP_H

#define FILENAME_SIZE 1024
#define BUFFSIZE 5

void startHelpFunction();

void numPrintMessage();

void clearBuffer();

int intParseConvert(char* int_buff);

int newintParseConvert(char* input_buffer, int input_buffer_length);

void strParse(char* buff, int numchar);





#endif