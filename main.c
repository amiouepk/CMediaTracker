#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//#include <bool.h>
#include <getopt.h>
#include "io_help.h"
#include "file_help.h"

//#include <gtk/gtk.h>

#define FILENAME_SIZE 100

//void exit
void TestOptions();
void TestFileOptions();
void GeneralOptions();
void FilesOptions();
void DefaultFileCreate();
void CustomFileCreate();
void RenameFile();


// **for now**
// handles input
int main(int argc, char** argv){

    int cmd_opt;

    const struct option long_options[] = {
        {"help",   no_argument, NULL, 'h'},
        {"test",   no_argument, NULL, 't'},
        {"normal", no_argument, NULL, 'n'},
        { NULL,    0,           NULL,  0 }
    };

    cmd_opt = getopt_long(argc, argv, "htn", long_options, NULL);

    switch (cmd_opt){
        case 'h':
            startHelpFunction();
            break;
        case 't':
            printf("test setting\n");
            TestOptions();
            break;
        case 'n':
            printf("normal setting\n");
            GeneralOptions();
            break;
        default:
            printf("please enter a valid setting\n");
            break;
    }
    
    exit(0);
}

void TestOptions(){

    int test_options;
    char* int_buff = malloc(1024 * sizeof(char));
    char* c_arr;

    while (1){

        printf("Test Options:\n");
        printf("  0. Exit program\n");
        printf("  1. Files: Access test file options\n");
        //printf("              \n");
        //printf("\n");
        printf("Number: ");
        test_options = intParseConvert(int_buff);

        switch(test_options){
            case 0:
                free(int_buff);
                return;
            case 1:
                TestFileOptions();
                break;
            case -1:
                numPrintMessage();
                break;
            default:
                numPrintMessage();
                break;

        }
    }

    return;
}


void GeneralOptions(){

    int general_option;
    char* int_buff = malloc(1024 * sizeof(char));
    
    while (1){
        printf("General Options:\n");
        //numPrintMessage();
        printf("  1. Files: Access file options\n");
        //printf("              \n");
        //printf("\n");
        printf("Number: ");
        if (!fgets(int_buff, 1024, stdin)){
            printf("Parsing failed, please entr again\n");
            continue;
        }

        switch(general_option){
            case 0:
                free(int_buff);
                return;
            case 1:
                FilesOptions();
                break;
            default:
                numPrintMessage();
                break;

        }
    }

    return;

}

void TestFileOptions(){

    int test_file_option;

    while (1){
        printf("Test File Options:\n");
        printf("  1. default: Creates default files with default names (can be customized further after creation)\n");
        printf("              further after creation)\n");
        printf("  2. rename : rename existing files\n");
        printf("  3. create : create new files\n");
        printf("  4. delete : delete existing files\n");
        printf("  5. exit   : exits file options (returns to General Options)\n");
        printf("********************************************************************\n");
        printf("  6. test check\n");
        //printf("")
        printf("Number: ");
        scanf("%i", &test_file_option);

        
        switch (test_file_option){
            case 0:
                return;
            case 1: 
                DefaultFileCreate();
                break;
            case 2:
                RenameFile();
                break;
            case 3:
                CustomFileCreate();
                break;
            case 6:
                ifFileExists("testFileName.txt");
                break;
            default:
                numPrintMessage();
                break;

        }
    }

    return;


    return;
}

void FilesOptions(){

    int file_option;

    while (1){
        printf("File Options:\n");
        printf("  1. default: Creates default files with default names (can be customized further after creation)\n");
        printf("              further after creation)\n");
        printf("  2. rename : rename existing files\n");
        printf("  3. create : create new files\n");
        printf("  4. delete : delete existing files\n");
        printf("  5. exit   : exits file options (returns to General Options)\n");
            printf("Number: ");
        scanf("%i", &file_option);
        
        switch (file_option){
            case 1: 
                DefaultFileCreate();
                break;
            case 2:
                RenameFile();
                break;
            case 3:
                CustomFileCreate();
                break;
            default:
                numPrintMessage();
                break;

        }
    }

    return;

}

void DefaultFileCreate(){
    


    return;
}

void RenameFile(){

    return;
}

void CustomFileCreate(){

    char* filename = malloc((FILENAME_SIZE + 5) * sizeof(char)); // +5 for .csv\0
    while (1){
        printf("Print name of file (upto 100 characters): ");
        // int filename_size = scanf("%100s", filename);
        // if (filename_size <= FILENAME_SIZE - 5){
        //     break;
        // }


        printf("Name is to long\n");
        printf("Please ");
    }



    if (ifFileExists(filename))
        return;
    
    FILE* fp = fopen(filename, "w+");
    if (!fp){
        perror("Error creating file");
        return;
    }

    if (fclose(fp) == EOF){
        perror("Error closing file");
        return;
    }

    printf("file is created\n");

    return;
}



