#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mp3tag 
{
    char tag[5];
    int size;
    char flag[3];
    char data[256];
};

extern struct mp3tag reader;  

void view(const char *filename);
void edit(const char *filename, const char *option, const char *new_content);
void read_tag(struct mp3tag *reader, FILE *fp);
void little(int *size);
void read_tag_size(struct mp3tag *reader, FILE *fp);
void help(void );

#endif
