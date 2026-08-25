#include <stdio.h>

#include "argv.h"

int main(int argc, char *argv[])
{
    if(argc == 1) {
        printf("Usage: %s <file>\n",argv[0]);
    }else {
        int flags = argv_flags(argc,argv);
	char *input_files = argv_input(argc,argv);
        char *output_file = argv_output(argc,argv);

        //file_check
        printf("Finding files!\n");
        //transforming
        printf("Converting files!\n");
        //linking
        printf("Combinding files!\n");
        //create_output_file
        printf("Creating Result!\n");
    }
}
