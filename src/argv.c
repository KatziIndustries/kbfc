#include <string.h>

int argv_flags(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--katzi") == 0) {
            return 1;
        }
    }

    return 0;
}

char *argv_input(int argc, char *argv[])
{
    int wasdasho = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0) {
            wasdasho = 1;
        } else {
            if (wasdasho == 0) {
                return argv[i];
            }
            wasdasho = 0;
        }
    }
    return NULL;
}

char *argv_output(int argc, char *argv[])
{
    int wasdasho = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0) {
            wasdasho = 1;
        } else {
            if (wasdasho == 1) {
                return argv[i];
            }
        }
    }
    return "out.bfos";
}
