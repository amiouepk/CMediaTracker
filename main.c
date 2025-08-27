#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//#include <bool.h>
#include <getopt.h>
//#include <gtk/gtk.h>


void startHelpFunction();
void GeneralOptions();
void FilesOptions();
void numPrintmessage();
void DefaultFileCreate();
void createFile();

// **for now**
// handles input
int main(int argc, char** argv){

    int cmd_opt;

    const struct option long_options[] = {
        {"help",        no_argument, NULL, 'h'},
        {"development", no_argument, NULL, 'd'},
        {"normal",      no_argument, NULL, 'n'},
        { NULL,         0,           NULL,  0 }
    };

    cmd_opt = getopt_long(argc, argv, "hdn", long_options, NULL);

    switch (cmd_opt){
        case 'h':
            startHelpFunction();
            break;
        case 'd':
            printf("developer setting\n");
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

void startHelpFunction(){

    printf("Start options:\n");
    printf("  -h, --help         shows this help message and exits\n");
    printf("  -d, --development  enables aditional options and more verbose results\n");
    printf("  -n, --normal       enables working options and regular results\n");

    return;
}

void GeneralOptions(){

    int general_option;
    

    while (1){
        printf("General Options:\n");
        numPrintmessage();
        printf("  1. Files: Access file options\n");
        //printf("              \n");
        //printf("\n");
        printf("Number: ");
        scanf("%d", &general_option);
        printf("scanned\n");

        switch(general_option){
            case 1:
                FilesOptions();
                break;
            default:
                printf("Please Enter a number 1-9\n");

        }
    }


    return;
}

void FilesOptions(){

    // int* options = calloc(sizeof(int), 4);
    // if (!options){
    //     perror("options array calloc error");
    //     exit(EXIT_FAILURE);
    // }

    
    //printf("  \n");
    int file_option;

    while (1){
        printf("File Options:\n");
        numPrintmessage();
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

        }
    }

    return;

}

void numPrintmessage(){

    printf("  Type a number 1-9 according to the list below\n");
    return;
}


