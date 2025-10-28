//#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
//#include <bool.h>
#include "io_help.h"

#define STDIN 0

//#define FILENAME_SIZE 1024

void startHelpFunction(){

    printf("Start options:\n");
    printf("  -h, --help         shows this help message and exits\n");
    printf("  -d, --development  enables aditional options and more verbose results\n");
    printf("  -n, --normal       enables working options and regular results\n");

    return;
}

void numPrintMessage(){
    //printf("\n");
    printf("Type a number 1-9 according to the list below\n");
    return;
}

/*
 * confused as too the efficacy of the implementation of this function. I cannot tell if it is
 * alright to use the same buffer as the input buffer. I want to return an error if the chars_read
 * seems to be greater than it needs to be. the length the input string needs to be doesnt seem to
 * be the length of the input buffer, and it probably shouldn't sepecially if i want to implement
 * my own null termination. What do I do if the input is longer than it should be? I should either
 * return an error, or i should just cut off the input and use the x number character work and 
 * pass back to function. I want to return error for sure. How do I do this? i could do an
 * internal check, and check if chars_read exceeds the desired length using chars_read. I might
 * try and do this. And when and how should i clean the buffer? should i do so no matter what? I 
 * built in an immeidate return of chars_read is less than input_buffer_length. 
 */  

 
/*
 * The way the clear funciton is going to be used in the future:
 * IF it is determined that the buffer needs to be cleared, you call the clearBuffer function.
 * This is IF is determined via the following criteria:
 *  1. Is the input amount larger than what is should be?
 *  2. Was the input characters invalid in some way (for int parse)
 *  
 * 
 */

static void clearBuffer(char* input_buffer, int input_buffer_length){

    int c;

    while ( (c = getchar()) != '\n' && c != EOF ) { }

    return;
}

//returns size
int strParse(char* input_buffer, int length_limit){

    //int converted_int;
    
    int chars_read = read(STDIN, input_buffer, length_limit);
    if (chars_read < 0){
        perror("read error");
        errno = 0;
        return -1;
    }

    if (chars_read > length_limit){
        fprintf(stderr, "Error: Maximum character limit is %d", length_limit);
        clearBuffer(input_buffer, BUFFSIZE);
        return -1;

    }

    // null termination portion to make printing strings more convenient
    input_buffer[chars_read - 1] = '\0';

    return chars_read + 1;
}

//Need to implement non blocking with fcntl for reads to cleaer buffer later, not tryna do that rn

int intParseConvert(char* input_buffer, int length_limit) {
    
    int converted_int = -1;
    
    int chars_read = read(STDIN, input_buffer, BUFFSIZE);
    if (chars_read < 0){
        perror("read error");
        errno = 0;
        return converted_int;
    }
    
    // printf("chars_read: %d\n", chars_read);
    char* endptr;
    converted_int = strtol(input_buffer, &endptr, 0);
    
    if (errno != 0){
        perror("Unsupported value");
        errno = 0;
        return converted_int;
    }

    if (endptr == input_buffer) {
        fprintf(stderr, "Error: No valid digits found in input.\n");
        clearBuffer(input_buffer, BUFFSIZE);
        return -1; // Or some other error indicator
    }

    if (*endptr != '\0'){
        printf("chars_read: %d\n", chars_read);

        clearBuffer(input_buffer, BUFFSIZE);

        return converted_int;
        
    }

    
    //

    return converted_int;
}


int oldintParseConvert(char* int_buff){

    int conv_int;
    char* endptr;

    if (!fgets(int_buff, 1024, stdin)){
        printf("Parsing failed, please enter again\n");
        return -1;
    }

    errno = 0;

    conv_int = strtol(int_buff, &endptr, 10);
    if (errno != 0){
        perror("Parsing error: check entered number");
        errno = 0;
        return -1;
    }
    if (endptr == int_buff){
        fprintf(stderr, "No digits were found\n");
        return -1;
    }

    return conv_int;
}


void oldstrParse(char* buff, int numchar){
    
    //plus two to make space for '\n' and '\0'
    //include '\n' because if the size is <= 1024, '\n' will be present, but if > 1024, it will not be present

    if (!fgets(buff, numchar + 2, stdin)){
        printf("Parsing failed, please enter again\n");
        clearBuffer(buff, numchar);
        //return -1;
    }
    
    char* buff_check = strchr(buff, '\n');
    //printf("buff_check: %c\n", buff_check);
    if (buff_check == NULL){
        printf("Please make sure name is under %d characters\n", FILENAME_SIZE);
        clearBuffer(buff, numchar);
    }

    for (int i = 0; i < numchar; i++){
        if (buff[i] == '\n'){
            printf("/n");
            continue;
        }
        if (buff[i] == '\0'){
            printf("/0");
            continue;
        }
        printf("%c", buff[i]);
    }

    printf("\n");
        

    return;
}




