#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//#include <bool.h>
#include "io_help.h"


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

int intParseConvert(char* int_buff){

    int conv_int;
    char* endptr;


    if (!fgets(int_buff, 1024, stdin)){
        printf("Parsing failed, please entr again\n");
        return -1;
    }

    errno = 0;
    //test_options = 0;

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


