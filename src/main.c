#include <stdio.h>

#include "argv.h"
#include "file.h"

int main(int argc, char *argv[])
{
    if(argc == 1) {
        printf("Usage: %s <file>\n",argv[0]);
    }else {
        int flags = argv_flags(argc,argv);
	char *input_file = argv_input(argc,argv);
        char *output_file = argv_output(argc,argv);

        if (input_file == NULL) {
            printf("%s: no input files found\n",argv[0]);
            return 1;
        }

        int check_in = file_check(input_file);
        int check_out = file_check(output_file);

        if (check_in == 0) {
            printf("%s cannot find %s: No such file or directory\n",argv[0],input_file);
            return 1;
        }

        if (check_out == 1) {
            printf("%s cannot create %s: File already exists\n",argv[0],output_file);
            return 1;
        }

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
