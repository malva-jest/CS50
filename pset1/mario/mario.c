#include <cs50.h>
#include <stdio.h>

void printSpaces(int num_spaces);
void printHashes(int num_spaces);
void nextLine();
void printMiddleSpaces();

int main(void)
{

    int num_rows;
    do
    {
        num_rows = get_int("How many rows do you want?\n");
    }
    while (num_rows < 1 || num_rows > 8);
    // int num_rows = get_int("How many rows do you want?\n");
    for (int row = 1; row <= num_rows; row++)
    {
        printSpaces(num_rows - row);
        printHashes(row);
        // printMiddleSpaces();
        nextLine();
    }
}

void printSpaces(int num_spaces)
{
    for (int i = 1; i <= num_spaces; i++)
    {
        printf(" ");
    }
}

void printHashes(int num_hashes)
{
    for (int i = 1; i <= num_hashes; i++)
    {
        printf("#");
    }
}

void nextLine()
{
    printf("\n");
}

void printMiddleSpaces()
{
    printf(" ");
}

// #include<stdio.h>
// int main()
// {
//     int noOfRows, row, colA, colB, noOfCol;

//     do
//     {
//         printf("Height: ");
//         scanf("%d", &noOfRows);
//     }

// // ensures do while continues till we received the desired integer
//     while (noOfRows < 1 || noOfRows > 8);

//     noOfCol = noOfRows - 1;

// // skips to new line when conditions of inner loop are satisfied
//     for (row = 1; row <= noOfRows; row++)
//     {
// // print spaces equal to 1 less than the integer provided
//         for (colA = 1; colA <= noOfCol;
//         colA++)
//         {
//             printf(" ");
//         }
// // print an '*' equal in number to our row and increment till we reach the value of the integer provided
//         noOfCol--;

//         for (colB = 1; colB <= row; colB++)
//         {
//             printf("*");
//         }
//         printf("\n");
//     }
// }

