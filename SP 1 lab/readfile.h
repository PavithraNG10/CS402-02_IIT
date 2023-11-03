#ifndef READFILE_H
#define READFILE_H

int open_file(const char *filename);
int read_int(int *n);
int read_float(float *f);
int read_string(char *s);
void close_file();

#endif