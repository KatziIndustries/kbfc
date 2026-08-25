#include <unistd.h>

int file_check(char *fname)
{
    return (access(fname, F_OK) == 0);
}


