// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);




    uint8_t header[HEADER_SIZE]; // "replacing n with the number of bytes."

    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    int16_t buffer;
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

//------------------------------------------------


    // TODO: Copy header from input file to output file

    // TODO: Read samples from input file and write updated data to output file


    // fread the content of your wav
    // this is for our wav header
    // uint8_t is a type that stores an 8-bit (1 byte) unsigned (i.e., not negative) integer


    // FILE *input = fopen("INPUT.wav", "r"); --------> erase because you've already opened the files
    // if (input != NULL)
    // {
    // char c; --------> I've amended this with uint8_t for my purposes








    // }




// seems alright, but I have no idea how to multiply each sample by 2 in order to adjust the volume
// doesn't even make sense -- how does this multiplication actually translate into volume ...?








//------------------------------------------------


    // This if conditional below just seem pointless ... we've already checked for NULL

    // FILE *output = fopen("OUTPUT.txt", "w"); --------> erase because you've already opened the files
    // if (output == NULL) // --------> I don't understand why we need to check this again
    // {
    //     fclose(input);
    //     return 1;
    // }


//------------------------------------------------


    // This function copies the string at src, including its terminating 0, to the memory at dest.

    // char *s = get_string("s: ");
    // if (s != NULL)
    // {
    //     char *t = malloc(strlen(s) + 1);
    //     if (t != NULL)
    //     {
    //         strcpy(t, s);
    //         printf("s: %s\n", s);
    //         printf("t: %s\n", t);
    //     }
    // }


//------------------------------------------------

// Notes to self:

    /* The header contains meta-data, therefore, it's not necessary
    to amend the values at the memory address.
    Meaning, we should be able to read from and write to our desired location.
    */

    /*
    We are dealing with call by reference in this problem. :)
    We are not passing values -- we're passing addresses.
    We are not working with copies of values, but rather the values themselves.
    */


    /*
    Maybe we can skip reopening and just go straight into
    the fread and fwrite stuff because we have the error logic above in template code
    not entirely sure if strcpy is needed
    */

//------------------------------------------------
// fwrite

    // FILE *input = fopen("input.txt", "r"); ------> I'm including *input into fopen above for convention-sake
    // if (input == NULL) ------> same thing here (notice the == is different to !=)
    // {
    //     return 1;
    // }
//------------------------------------------------

// chaning the value of 5 to 4
// int x = 5;
// int *ptr = &x;
// *ptr = 4;

// // what if we said ...

// int temp;
//     temp = *input;
//     *input = *output;
//     *output = temp;

// int temp;
//     temp = *n1;
//     *n1 = *n2;
//     *n2 = temp;


//------------------------------------------------

    // Close files
    fclose(input);
    fclose(output);
}






