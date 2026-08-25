#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc == 1) {
        printf("Usage: %s <file>\n",argv[0]);
    }else {
        //argv
        printf("Extracting argv!\n");
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
