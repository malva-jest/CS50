#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int index = 0.0588 * L - 0.296 * S - 15.8;
int L = (Sen/Lett * 100);
int S = (Sen/W * 100);

int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int main ()
{

    string input = get_string("Text: ");
    printf("%s", input);

    int step1 = count_letters(input);
    printf("%i\n", step1);
    int step2 = count_words(input);
    printf("%i\n", step2);
    int step3 = count_sentences(input);
    printf("%i\n", step3);

    // Printing out the Grade level
    if (index >= 16)
    {
        print("Grade 16+");
    }
    else if (index == 1)
    {
        print("Grade 1");
    }
    else if (index == 2)
    {
        print("Grade 2");
    }
    else if (index == 3)
    {
        print("Grade 3");
    }
    else if (index == 4)
    {
        print("Grade 4");
    }
    else if (index == 5)
    {
        print("Grade 5");
    }
    else if (index == 6)
    {
        print("Grade 6");
    }
    else if (index == 7)
    {
        print("Grade 7");
    }
    else if (index == 8)
    {
        print("Grade 8");
    }
    else if (index == 9)
    {
        print("Grade 9");
    }
    else if (index == 10)
    {
        print("Grade 10");
    }
    else
    {
        printf("college level");
    }

}
// -----------------------------------
int count_letters(string text)
//take the input and count the characters in each word
//ignore the spaces
//sum up the total letters
    int Lett = 0;
{
    for (int i = 0; len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i])
        {
            Lett++;
        }
        }
    }
    return round(Lett);
}
// -----------------------------------
int count_words(string text)
//count the words in a sentence
//a sentence ends with a full stop
//sum all the words in the sentence
int W = 0;
{
    for (int i = 0; len = strlen(text); i < len; i++)
    {
        while (text[i] != '\0')
        W++;
    }
    return round(W);
}
// -----------------------------------
//counts the sentences in the input
//sum the sentences
int count_sentences(string text)
int Sen = 0;
{
    for (int i = 0; len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || '?' || '!')
        Sen++;
    }
    return Sen;
}

