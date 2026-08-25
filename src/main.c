#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "argv.h"
#include "file.h"
#include "transform.h"

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

        FILE *in_file = fopen(input_file, "rb");
        if (!in_file) {
            perror("fopen");
            return 1;
        }

        fseek(in_file, 0, SEEK_END);
        long size = ftell(in_file);
        rewind(in_file);

        char *data = malloc(size);
        if (!data) {
            fclose(in_file);
            return 1;
        }

        size_t bytes_read = fread(data, 1, size, in_file);
        fclose(in_file);

        data[0] = 'B';
        data[1] = 'F';
        data[2] = 'O';
        data[3] = 'S';

        size_t out = 4;

        for (size_t i = 0; i < bytes_read; i++) {
             unsigned char result = transform(data[i]);

             if (result != 0xff) {
                 data[out++] = result;
             }
        }

        bytes_read= out;

        FILE *out_file = fopen(output_file, "wb");
        if (!out_file) {
            perror("fopen");
            free(data);
            return 1;
        }

        fwrite(data, 1, bytes_read, out_file);

        fclose(out_file);
        free(data);

        return 0;
    }
}
