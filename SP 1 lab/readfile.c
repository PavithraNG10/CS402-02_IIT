
#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"

static FILE *file;

int open_file(const char *filename) {
    file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }
    return 0;
}

int read_int(int *n) {
    if (fscanf(file, "%d", n) != 1) {
        return -1;
    }
    return 0;
}

int read_float(float *f) {
    if (fscanf(file, "%f", f) != 1) {
        return -1;
    }
    return 0;
}

int read_string(char *s) {
    if (fscanf(file, "%s", s) != 1) {
        return -1;
    }
    return 0;
}

void close_file() {
    fclose(file);
}