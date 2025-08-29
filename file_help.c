#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//#include <bool.h>
#include <getopt.h>
#include <unistd.h>
#include "print_help.h"


int ifFileExists(char* name){

    if (!access(name, F_OK)){
        printf("A file with this name may have already been created\n");
        printf("Please check file directory\n");
        return -1;
    }
    
    // if (!access(name, R_OK | W_OK)){
    //     printf("Check file read and write permissions\n");
    //     return;
    // }
    
    return 0;


}

void createFile(const char* name, FILE* fp){

    fp = fopen(name, "w+");

    if (!fp){
        perror("Error creating new file");
        return;
    }

    return;

}



