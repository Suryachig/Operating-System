/*######################################################
Author: Surya Chigurupati
Program Name: copier.c
Description: Take two file names as arguments and
             copy data from one file to another
Class: Introduction to Operating Systems (Spring17)
Last Modified: 02/4/2017 3:37 P.M.
######################################################*/

#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char *argv[] )
{

char ch;
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
            printf( "There is no such file.\n" );
            exit(EXIT_FAILURE);
        }

   /* Copy the data from source file to destination file */
   while( ( ch = fgetc(source) ) != EOF )
      fputc(ch, destination);
   
   /* Print program status */
   printf("File copied successfully.\n");
 
   /* Close both source and destination files */
   fclose(source);
   fclose(destination);

    return 0;
}
}
