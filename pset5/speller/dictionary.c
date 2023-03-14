// Implements a dictionary's functionality
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>
#include <cs50.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


int wordCount = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int key = hash(word);

    node *nodePtr = table[key];

    while (nodePtr != NULL)
    {
        if (strcasecmp(nodePtr->word, word) == 0)
        {
            return true;
        }
        nodePtr = nodePtr->next;
    }

    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    int value = 0;
    for (int i = 0; i < word[i] != '\0'; i++)
    {
        value += tolower(word[i]);
    }
    return (value % N);
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *filePtr = fopen(dictionary, "r"); // you changed the first argument from argv[1]
    if (filePtr == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char tempWord[LENGTH + 1];
    //Read strings from file one at a time
    // fscanf(file, '%s', word)
    while (fscanf(filePtr, "%s\n", tempWord) != EOF)
    {
        node *tempNode = malloc(sizeof(node));

        strcpy(tempNode->word, tempWord);

        int key = hash(tempWord);

        if (table[key] == NULL)
        {
            tempNode->next = NULL;
            table[key] = tempNode;
        }
        else
        {
            tempNode->next = table[key];
            table[key] = tempNode;
        }
        wordCount++;
    }
    fclose(filePtr);
    return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *nodePtr = table[i];

        while (nodePtr != NULL)
        {
            node *deleteMe = nodePtr;
            nodePtr = nodePtr->next;
            free(deleteMe);
        }

        table[i] = NULL;
    }
    return true;
}








// ------------------

// Implements a dictionary's functionality
// #include <strings.h>
// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <ctype.h>
// #include <stdbool.h>
// #include <cs50.h>


// #include "dictionary.h"

// // Represents a node in a hash table
// typedef struct node
// {
//     char word[LENGTH + 1];
//     struct node *next;
// }
// node;




// // TODO: Choose number of buckets in hash table
// const unsigned int N = (LENGTH + 1) * 'z';



// // Hash table
// node *table[N];

// int total_words = 0;





// // Returns true if word is in dictionary, else false
// bool check(const char *word)
// {
//     // hash word to obtain hash value
//     int index = hash(word);
//     // access linked list at that index in hash table
//     node *cursor = table[index];
//     // traverse linked list looking for word with strcasecmp
//     while (cursor != NULL)
//     {
//         if (strcasecmp(cursor->word,word) == 0)
//         {
//             return true;
//         }
//         cursor = cursor->next;
//     }
//     return false;
// }





// // Hashes word to a number
// unsigned int hash(const char *word)
// {
//     int sum = 0;
//     for (int i = 0; i < strlen(word); i++)
//     {
//         sum += tolower(word[i]);
//     }
//     return (sum % N);
// }




// // Loads dictionary into memory, returning true if successful, else false
// bool load(const char *dictionary)
// {
//     // TODO
//     FILE *DictFile = fopen(dictionary, "r"); // you changed the first argument from argv[1]
//     if (DictFile == NULL)
//     {
//         return false;
//     }

//     //Read strings from file one at a time
//     // fscanf(file, '%s', word)
//     char word[LENGTH + 1];
//     while (fscanf(DictFile, "%s\n", word) != EOF)
//     {
//         // Create a mew node for each word
//         // Use malloc
//         node *new_node = malloc(sizeof(node));
//         // Check if return value is NULL
//         if (new_node == NULL)
//         {
//             return false;
//         }
//         // Copy word into node using strcpy
//         strcpy(new_node->word, word);
//         new_node->next = NULL;

//         // Use the hash function
//         int index = hash(word);

//         // Check if the head is pointing to NULL
//         if (table[index] == NULL)
//         {
//             // Point temp to NULL
//             table[index] = new_node;
//         }
//         else
//         {
//             // Otherwise, point temp to the first node of the linked list
//             new_node->next = table[index];
//             table[index] = new_node;
//         }
//     }
//     total_words++;

//     // Close the file
//     fclose(DictFile);
//     return true;
// }







// // Returns number of words in dictionary if loaded, else 0 if not yet loaded
// unsigned int size(void)
// {
//     return total_words;
// }




// // Unloads dictionary from memory, returning true if successful, else false
// bool unload(void)
// {
//     for (int i = 0; i < N; i++)
//     {
//         node *head = table[i];
//         node *cursor = head;
//         node *temp = head;

//         while (cursor != NULL)
//         {
//             cursor = cursor->next;
//             free(temp);
//             temp = cursor;
//         }
//     }
//     return true;
// }
