#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//#include <bool.h>
#include <getopt.h>
#include "print_help.h"


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



