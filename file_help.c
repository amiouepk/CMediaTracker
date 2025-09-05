#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//#include <bool.h>
#include <unistd.h>
//#include "io_help.h"


int ifFileExists(char* name){

    if (!access(name, F_OK)){
        printf("A file with this name may have already been created\n");
        printf("Please check file directory\n");
        return 1;
    }
        
    return 0;
}

void createFile(const char* name){

    FILE* fp = fopen(name, "w+");

    if (!fp){
        perror("Error creating new file");
        return;
    }

    fclose(fp);

    return;

}



