//#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
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
    printf("\n");
    printf("Type a number 1-9 according to the list below\n");
    return;
}

void clearBuffer(){
    
    int c;
    do {
        c = getchar();
        //printf("%c", c);
    } while (c != '\0' && c != EOF);
    
    return;
}

int newintParseConvert(char* input_buffer, int input_buffer_length){
    
    int converted_int;
    
    int chars_read = read(STDIN, input_buffer, input_buffer_length);
    if (chars_read < 0){
        perror("read error");
        errno = 0;
        return -1;
    }
    
    // printf("chars_read: %d\n", chars_read);

    converted_int = strtol(input_buffer, NULL, 0);


    return converted_int;
}

int intParseConvert(char* int_buff){

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


void newStrParse(char* input_buffer, int input_buffer_length){

    //int converted_int;
    
    int chars_read = read(STDIN, input_buffer, input_buffer_length);
    if (chars_read < 0){
        perror("read error");
        errno = 0;
        return;
    }



    return;
}

void strParse(char* buff, int numchar){
    
    //plus two to make space for '\n' and '\0'
    //include '\n' because if the size is <= 1024, '\n' will be present, but if > 1024, it will not be present

    if (!fgets(buff, numchar + 2, stdin)){
        printf("Parsing failed, please enter again\n");
        clearBuffer();
        //return -1;
    }
    
    char* buff_check = strchr(buff, '\n');
    //printf("buff_check: %c\n", buff_check);
    if (buff_check == NULL){
        printf("Please make sure name is under %d characters\n", FILENAME_SIZE);
        clearBuffer();
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




