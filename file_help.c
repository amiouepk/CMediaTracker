#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//#include <bool.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
//#include "io_help.h"


int ifFileExists(char* name){

    if (!access(name, F_OK)){
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

char* filenameFilter(char* filename_raw){

    printf("raw filename: %s\n", filename_raw);

    char* filename_filtered;

    int filename_raw_size = strlen(filename_raw);
    int filename_filtered_size;
    //int filename_filtered_size = newline_location + 1;

    for (int i = 0; i < filename_raw_size; i++){
        if (filename_raw[i] == '\n'){
            filename_filtered_size = i + 1;
            break;
        }
    }
    printf("filename_filtered_size: %s\n", filename_filtered_size);

    filename_filtered = malloc(filename_filtered_size * sizeof(char));
    
    strncpy(filename_filtered, filename_raw, filename_filtered_size);
    filename_filtered[filename_filtered_size - 1] = '\0';

    free(filename_raw);

    printf("Filtered Filename: %s\n", filename_filtered);

    return filename_filtered;
}



