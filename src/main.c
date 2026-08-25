#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc == 1) {
        printf("Usage: %s <file>\n",argv[0]);
    }else {
        printf("Finding files!\n");
    }
}
