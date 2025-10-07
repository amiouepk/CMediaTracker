#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//#include <bool.h>
#include <getopt.h>
#include "io_help.h"
#include "file_help.h"

//#include <gtk/gtk.h>

//#define FILENAME_SIZE 100

// Random access file

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
    char* input_buffer = malloc(BUFFSIZE * sizeof(char));
    char* c_arr;

    while (1){

        printf("Test Options:\n");
        printf("  0. Exit program\n");
        printf("  1. Files: Access test file options\n");
        printf("  2. Modify Options\n");
        //printf("              \n");
        //printf("\n");
        printf("Number: ");
        test_options = newintParseConvert(input_buffer, BUFFSIZE);

        switch(test_options){
            case 0:
                free(input_buffer);
                return;
            case 1:
                TestFileOptions(input_buffer);
                break;
            case 2:
                printf("not ready yet\n");
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
    char* input_buffer = malloc(1024 * sizeof(char));
    
    while (1){
        printf("General Options:\n");
        //numPrintMessage();
        printf("  0. Exit program\n");
        printf("  1. Files: Access file options\n");
        //printf("              \n");
        //printf("\n");
        printf("Number: ");
        general_option = newintParseConvert(input_buffer, BUFFSIZE);


        switch(general_option){
            case 0:
                free(input_buffer);
                return;
            case 1:
                FilesOptions(input_buffer);
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

void TestFileOptions(char* input_buffer){

    int test_file_option;
    //char* input_buffer = malloc(1024 * sizeof(char));
    //char* buff = malloc(10 * sizeof(char));

    while (1){
        printf("Test File Options:\n");
        printf("  0. Exit Test File Options\n");
        printf("  1. default: Creates default files with default names (can be customized further after creation)\n");
        printf("              further after creation)\n");
        printf("  2. rename : rename existing files\n");
        printf("  3. create : create new files\n");
        printf("  4. delete : delete existing files\n");
        printf("********************************************************************\n");
        printf("  5. test ifFileExists\n");
        printf("  6. test strParse\n");
        //printf("  7. test createFile\n");
        //printf("")
        printf("Number: ");
        test_file_option = newintParseConvert(input_buffer, BUFFSIZE);

        
        switch (test_file_option){
            case 0:
                //free(input_buffer);
                //free(buff);
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
            case 5:
                ifFileExists("testFileName.txt");
                break;
            case 6:
                printf("enter a string: \n");
                break;
            default:
                numPrintMessage();
                break;

        }
    }

    return;


    return;
}

void FilesOptions(char* input_buffer){

    int file_option;

    while (1){
        printf("File Options:\n");
        printf("  0. Exit File Options\n");
        printf("  1. default: Creates default files with default names (can be customized further after creation)\n");
        printf("              further after creation)\n");
        printf("  2. rename : rename existing files\n");
        printf("  3. create : create new files\n");
        printf("  4. delete : delete existing files\n");
        printf("  5. exit   : exits file options (returns to General Options)\n");
        printf("Number: ");
        file_option = newintParseConvert(input_buffer, BUFFSIZE);
        
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

    const char* filename = "text.txt";

    


    return;
}



