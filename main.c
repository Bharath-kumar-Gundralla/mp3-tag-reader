
#include<stdio.h>
#include<string.h>
#include "header.h"
void main(int argc, char *argv[])
{
    if (argc < 2)
    { 
        printf("-----------------------------------------------------------------\n");
        printf("ERROR: Not enough arguments\n"); 
        printf("-----------------------------------------------------------------\n");
        help();
        return;
    }
    if (strcmp(argv[1], "-v") == 0)   // if argv is -v open view part
    {
        view(argv[2]); 
    }
    else if(strcmp(argv[1],"-h")==0) //if argv 1 is -h display usage  menu to the user 
    {
        help();    // help part to print the menu 
    }
    else if (strcmp(argv[1], "-e") == 0) 
    {
       if (argc < 5)
        {
            printf("Not enough arguments\n"); // if arguments less than 5 then print error and display the menu 
            help();
            return;
        }
        if (argc == 5) // if argv 1 is -e and the argument is 5 then open edit part 
        {
            edit(argv[2], argv[3], argv[4]); 
        }
        else
        {
            printf("please enter proper arguments only\n");//display error 
            help(); // display usage menu 
        }
    }
    else
    {
        printf("unknown mode %s\n", argv[1]); // if the argv 1 is not -v or -e or -h then print error
        help();// display  help menu
    }
    return;
}
