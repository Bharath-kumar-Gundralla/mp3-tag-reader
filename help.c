#include "header.h"
 void help(void )
 {
    printf("Usage:\n");
        printf("--------------------------------------------\n");
        printf(" for view Mode:\n");
        printf("\n");
        printf(" ./a.out  -v <file name > \n");
        printf("--------------------------------------------\n");
        printf("for edit mode :\n");
        printf("\n");
        printf(" ./a.out  -e <file name> <option> <new tag>\n");
        printf("--------------------------------------------\n");
        printf("Options:\n");
        printf("  -t    Title\n");
        printf("  -a    Artist\n");
        printf("  -y    Year\n");
        printf("  -A    Album\n");
        printf("  -g    Genre\n");
        printf("  -c    Comment\n");
 }