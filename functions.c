#include "header.h"

struct mp3tag reader;
void read_tag(struct mp3tag *reader, FILE *fp) 
{
    fread(reader->tag, 4, 1, fp); // toread the tag from the file 
    reader->tag[4] = '\0';      //null termination 
}

void little(int *size) // swapping logic to change the endianess
{
    char *ch = (char *)size;
    char temp = ch[0];
    ch[0] = ch[3];
    ch[3] = temp;
    temp = ch[1];
    ch[1] = ch[2];
    ch[2] = temp;
}

void read_tag_size(struct mp3tag *reader, FILE *fp) 
{
    fread(&reader->size, 4, 1, fp); //to 4 bytes of the tagsize of the file 
    little(&reader->size);      //  to convert the big to lil endian 
}