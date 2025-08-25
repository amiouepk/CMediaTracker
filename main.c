#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
//#include <gtk/gtk.h>

void createFile();
void startHelpFunction();
void NormalMode();

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
            NormalMode();
            break;
        default:
            printf("please enter a valid setting\n");
            break;
    }
    
    exit(0);
}

void helpFunction(){

    printf("Start options:\n");
    printf("  -h, --help         shows this help message and exits\n");
    printf("  -d, --development  enables aditional options and more verbose results\n");
    printf("  -n, --normal       enables working options and regular results\n");

    return;
}

void NormalMode(){

    printf("Options: \n");
    printf("  createFile: Creates file for a given category. If file is already created\n");
    printf("              for a given category, use the rename");
    printf("");



    return;
}
