#include <cs50.h>
#include <stdio.h>



int main()
{
    int start;
    do
    {
        //prompt for start size
        start = get_int("Please enter a start size: ");
    }
    while (start < 9);

    int end;
    do
    {
        //prompt for end size
        end = get_int("Please enter an end size: ");
    }
    while (end < start);

    //track number of years
    int years = 0;

    //update the population until reached threshold
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        //update number of years
        years++;
    }
    //print updated number of years
    printf("Years: %i\n", years);



}

