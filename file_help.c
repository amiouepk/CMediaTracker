#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//#include <bool.h>
#include <getopt.h>
#include <unistd.h>
#include "print_help.h"


int ifFileExists(char* name){

    //char* full_name = strcat(name, ".csv");

    if (access(name, F_OK)){
        printf("A file with this name has already been created");
        return 0;
    }
    
    // if (!access(name, R_OK | W_OK)){
    //     printf("Check file read and write permissions\n");
    //     return;
    // }
    
    // printf("all is well\n");
    return -1;


}

void createFile(const char* name, FILE** fp){

    fp = fopen(name, "w+");

    if (!fp){
        perror("Error creating new file");
        return;
    }

    return;

}



