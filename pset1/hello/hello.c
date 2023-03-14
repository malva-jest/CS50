#include <stdio.h>
#include <cs50.h>

int main(void)
{
//the user string input is saved in a variable called is name//
    string name = get_string("What's your name: ");
//the compiler then prints the stored variable//
    printf("Hello %s\n", name);

    return 0;
}