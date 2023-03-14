#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//prototypes

int main( int argc, string argv[] )
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

string key = argv[1];

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

// get plaintext from the user
    string plaintext = get_string("plaintext: ");

// convert the key to an integer
    int k = atoi(key);
    printf("ciphertext: ");

//rotate the cipher
    for (int i = 0; i <strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 65) + k) %26 ) + 65);
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 97) + k) %26 ) + 97);
        }
        else
        {
            printf ("%c", plaintext[i]);
        }
    }
    printf("\n");
}




// Pseudocode:

// 1) Ensure command-line only accepts 1 argument
//     check the argument:
//         must only contains digits
// 2) Prompt the user for plaintext
// 3) Rotate the plain text per the key input
//     check that:
//         casing is preserved for upper and lower
//         spacing is preserved
//         symbols (like commas) are retained
// 4) print the output

