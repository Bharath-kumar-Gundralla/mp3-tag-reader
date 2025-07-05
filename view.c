

#include<stdio.h>
#include "header.h"

void view(const char *filename)
{
        printf("--------------------------------------------\n");
        printf("MP3 tag Reader and Editor \n");
        printf("----------------------------------------------\n");
        FILE *fp;
        fp=fopen(filename,"rb"); //open the file in binary mode 
        if (fp==NULL) 
        {
            printf("cannot open the file in view part \n"); //error message to find that file is not opening is view part 
            return ;
        }
        char id3[3]={0};
        fread(id3,3,1,fp);//reading the flags 
        if(strncmp(id3,"ID3",3)==0)//comparing the flags ID3 to check if the file is id3 or not 
        {
            printf("ID3v2 tag detected\n");
            printf("--------------------------------------------\n"); 
        }
        else
        {
            printf("No idv3 tag detected\n");
           return;
        }
        fseek(fp,10,SEEK_SET);//skip 10 bytes for header
         for(int i=0;i<6;i++)
        {
           read_tag(&reader,fp);//read the tag 
            read_tag_size(&reader,fp);//read the tag size from the sample.mp3 
            fseek(fp,3,SEEK_CUR);// 3 flags the skipped from the current position 
            fread(reader.data,reader.size -1, 1, fp);//read the tag data
            reader.data[reader.size -1] = '\0';//null terminated

            if (strcmp(reader.tag, "TIT2") == 0)   // comapring the read.tag with the tit2 
            {
                printf("Title       :%s\n",reader.data); // if it is matches then print the title 
            }
            else if (strcmp(reader.tag, "TPE1") == 0)  // comapring the read.tag with the TPE1  
            {
                printf("Artist      :%s\n",reader.data);// if it is matches then print the artist name
            } 
            else if (strcmp(reader.tag, "TALB") == 0)
            {
                printf("Album       :%s\n",reader.data);  // comapring the read.tag with the TALB if matches print the album 
            } 
            else if (strcmp(reader.tag, "TYER") == 0)
            {
                printf("Year        :%s\n",reader.data); // comapring the read.tag with the TYER  if matches print the year
            }
            else if (strcmp(reader.tag, "TCON") == 0)  
            {
                printf("Genre       :%s\n",reader.data);// comapring the read.tag with the Tcon  if matches print the genre 
            }
            else if(strcmp(reader.tag, "COMM") == 0)  // comapring the read.tag with the tit2 
            {
                printf("Comment     :%s\n",reader.data);
            }

        } 
        fclose(fp); // close the file after reading 
        return ;
}