#ifndef IO_HELP_H
#define IO_HELP_H

#define FILENAME_SIZE 100
#define BUFFSIZE 128
#define INT_PARSE_SIZE 2

void startHelpFunction();

void numPrintMessage();

//void clearBuffer();

int oldintParseConvert(char* int_buff);

int intParseConvert(char* input_buffer, int length_limit);

void oldstrParse(char* buff, int numchar);

int strParse(char* input_buffer, int input_buffer_length);





#endif