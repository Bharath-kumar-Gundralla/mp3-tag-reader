#include "header.h"

void edit(const char*filename,const char *option,const char*new_content)
{
   printf("-----------------------------------------------------------------\n");
    FILE *oldfp=fopen(filename,"rb");
 //create  and open the old sample.mp3 file in read  binary mode 
    FILE *newfptr=fopen("temp.mp3","wb");// create new file pointer  and open the temp.mp3 in write binary mode

    if(oldfp==NULL)
    {
        printf(" ERROR : cannot open the old fp file\n"); // error message if the oldfile is not opened 
    }

    if(newfptr==NULL)
    {
        printf(" ERROR : cannot open the new fptr file\n");//error message if the newfile is not opened 
    }

    char header[10]; 
    fread(header,10,1,oldfp); //read the 10 bytes of header from the old file 
    fwrite(header,10,1,newfptr);// and write the 10  bytes header to the new file 

    char modifier[5];
        if(strcmp(option,"-t")==0)   // compare the user entered modifier with the option 
        {
            printf("----------->  you selected title to change <------------------\n");
            printf("--------------------------------------------------------------\n");
            strcpy(modifier,"TIT2"); // if it matches then copy the title to modifier 
        }

        else if(strcmp(option,"-a")==0)
        {
            printf("------------> you selected artist to change  <----------\n");
            printf("----------------------------------------------------------\n");
            strcpy(modifier,"TPE1");// if it matches then copy the artist to modifier 
        }

         else if(strcmp(option,"-y")==0)
        {
            printf("------------> you selected  year to change <-----------------\n");
            printf("--------------------------------------------------------------\n");
            strcpy(modifier,"TYER");// if it matches then copy the year to modifier 
        }

         else if(strcmp(option,"-A")==0)
        {
            printf("------------> you selected album to change   <---------------\n");
            printf("--------------------------------------------------------------\n");
            strcpy(modifier,"TALB");// if it matches then copy the album to modifier 
        }

         else if(strcmp(option,"-g")==0)
        {
            printf("-----------> you selected genre to change  <-------------\n");
            printf("--------------------------------------------------------\n");
           strcpy(modifier,"TCON");//// if it matches then copy the genre to modifier 
        }

         else if(strcmp(option,"-c")==0)
        {
            printf("--------------select comment to change----------------------\n");
            printf("------------------------------------------------------------\n");
           strcpy(modifier,"COMM");// if it matches then copy the comment  to modifier 
        }

        else
        {
            printf("Unknown tag ! please select option from given options menu \n");
            printf("-------------------------------------------------------------\n");
            help();

        }

    for(int i=0;i<6;i++)    // reading 6 tags to loop upto 6 
    {     
        read_tag(&reader,oldfp); // read the the tag from the from
        read_tag_size(&reader,oldfp);
        if(strcmp(reader.tag,modifier)==0) // compare the modifier with tag if it matches then read tag,tag size,tag data
        {
            fwrite(reader.tag, 4, 1, newfptr); //write the tag into new file
            int newsize=strlen(new_content)+1;
            little(&newsize); // convert the endianess
            fwrite(&newsize, sizeof(int), 1, newfptr);// write the new size to the newfile 
            fread(reader.flag,3,1,oldfp); // read 3 flags from old file
            fwrite(reader.flag, 3, 1, newfptr); // write the flags into the new file 
            little(&newsize); // convert the little endian to bigendian
            fwrite(new_content,newsize-1, 1, newfptr); // write the new data to the new file without null
            fseek(oldfp,reader.size - 1, SEEK_CUR);
            printf("Updated tag %s with \"%s\"\n", modifier, new_content); 
            break;
        }
        else
        {
            fwrite(reader.tag, 4, 1, newfptr);//write the tag to the new file
            int rs = reader.size;
            little(&rs);// changing the endianess
            fwrite(&rs, 4, 1, newfptr);
            fread(reader.flag,3,1,oldfp);//read the flags from the old file
            fwrite(&reader.flag, 3, 1, newfptr);//write the flags to the new file
            char *b = (char*)malloc(reader.size - 1);//allocate memory of tag size-1 
            fread(b, reader.size-1, 1, oldfp);//read data
            fwrite(b, reader.size-1, 1, newfptr);//write data
            free(b);// de-allocating the b 
        }
    }
    char ch;
    while(fread(&ch,1,1,oldfp)>0) // copy the remaining data of the oldfile to newfile 
    fwrite(&ch,1,1,newfptr);

    fclose(oldfp); // close old file 
    fclose(newfptr);// close the new file

    remove(filename);//remove the oldfile name 
    rename("temp.mp3",filename);//rename the new  file with the old file name
}