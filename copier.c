/*######################################################
Author: Surya Chigurupati
Program Name: copier.c
Description: Take two file names as arguments and
             copy data from one file to another.
Class: Introduction to Operating Systems (Spring17)
Last Modified: 02/9/2017 9:09 P.M.
######################################################*/

#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] )
{

int read, write;
char buffer[1024];
FILE *source, *destination;

    /* argc should be 3 for program to work */
    if ( argc != 3 )
    {
        
        printf("Sorry, I need two file names to execute the program.\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
        /* Assume argv[1] is the file to read from. */
        source = fopen( argv[1], "r" );

        /* Returns the NULL pointer, on failure */
        if ( source == NULL )
        {
            printf( "There is no such file.\n" );
            exit(EXIT_FAILURE);
        }

        /* Assume argv[2] is the file to copy to. */
        destination = fopen(argv[2], "w");

        /* Returns the NULL pointer, on failure */
        if ( destination == NULL )
        {
            printf( "Sorry, file could not be created.\n" );
            exit(EXIT_FAILURE);
        }

    /* Copy the data from source file to destination file byte by byte.*/
    while(feof(source)==0)
    {
        if((read=fread(buffer,1, 1024, source))!=1024)
            {
                 if(ferror(source)!=0)
                    {
                        exit(EXIT_FAILURE);
                    }
          else if(feof(source)!=0);
    }
    if((write=fwrite(buffer,1,read,destination))!=read)
    {
        exit(EXIT_FAILURE);
    }
    }

   /* Print program status */
   printf("File copied successfully.\n");

 
   /* Close both source and destination files */
   fclose(source);
   fclose(destination);

    return 0;
}
}
