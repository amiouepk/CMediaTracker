//#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
//#include <bool.h>
#include "io_help.h"

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
    } while (c != '\n' && c != EOF);
    
    return;
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
        return -1;
    }
    if (endptr == int_buff){
        fprintf(stderr, "No digits were found\n");
        return -1;
    }

    return conv_int;
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
        
    //printf("%s\n", buff);



    return;
}




