#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // ask how many cents the customer is owed
    int cents = get_cents();

    // calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // sum the coins
    int coins = quarters + dimes + nickels + pennies;

    // print the total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // function prompts user for number of cents using get_int
    // if the user tries to inpuy a negative int, prompt again
    int cents;
    do
    {
        cents = get_int("Change: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // function calculates how many quarters a customer should be given if they're owed some number of cents
    int count = 0;
    while (cents >= 25)
    {
        count++;
        cents = cents - 25;
    }
    return count;
}

int calculate_dimes(int cents)
{
    // function calculates how many dimes a customer should be given if they're owed some number of cents
    int count = 0;
    while (cents >= 10)
    {
        count++;
        cents = cents - 10;
    }
    return count;
}

int calculate_nickels(int cents)
{
    // function calculates how many nickels a customer should be given if they're owed some number of cents
    int count = 0;
    while (cents >= 5)
    {
        count++;
        cents = cents - 5;
    }
    return count;
}

int calculate_pennies(int cents)
{
    // function calculates how many pennies a customer should be given if they're owed some number of cents
    int count = 0;
    while (cents >= 1)
    {
        count++;
        cents = cents - 1;
    }
    return count;
}





// #include <stdio.h>
// #include <cs50.h>
// #include <math.h>

// int main(void)
// {

// //quarters, dimes, nickels, and total number of coins. a is float input for exact change.

//     int coincount = 0;
//     float a;

// //petitioning input
//     do
//     {
//         a = get_float("Gimme a positive value: ");
//     }
//     while (a <= 0);

// //converting float a to an integer i
//     float i = round(100 * a);

//     i = (int)i;

// //four 'while' loops checking quarters nickels dimes pennies and adding to coincount
//     while (i >= 25)
//     {
//         i = i - 25;
//         coincount++;
//     }
//     while (i >= 10)
//     {
//         i = i - 10;
//         coincount++;
//     }
//     while (i >= 5)
//     {
//         i = i - 5;
//         coincount++;
//     }

//     while (i >= 1)
//     {
//         i = i - 1;
//         coincount++;
//     }

// //printing sum of each coin type
//     {
//         printf("%i\n", coincount);
//     }
// }

