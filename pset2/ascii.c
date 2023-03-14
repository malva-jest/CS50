#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int n = 0;


int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

}

int compute_score(string word) // ---------------------------- this is a function 
{
    // TODO: Compute and return score for string
 
string some_word = strlen(word); // ---------------------------------- this variable should store the length of a string

    for (int i = 0; i < g; i++)
    {
        printf("%c", word[i]);
    }
    printf("\n");
}


// BREAK DOWN THE PROBLEM
// loop through the length of a string and ...
// assign each character in the string to an element in the array
// return the output

























  // TODO: Print the winner
    // if (score1 > score2) // (score1 >= 'a' && score1 <= 'z') || (score1 >= 'A' && score1 <= 'Z')
    // {
    //     printf("Player 1 wins!");
    // }
    // else if (score1 < score2)
    // {
    //     printf("Player 2 wins!");
    // }
    // else
    // {
    //     printf("Tie!");
    // }