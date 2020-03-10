#include <cs50.h>
#include <stdio.h>
#include <math.h>

// void compare_coins_with_change(int n);
// float coins_available[4] = {0.25, 0.10, 0.05, 0.01};

int main(void)
{
    // change owed as entered by user
    float change_owed;
    // variable to keep track of coins used
    int count = 0;
    do
    {
        change_owed = get_float("Change owed: ");
        // round cents to the nearest penny
        int cents = round(change_owed * 100);
        // checks if cents is within quarter range
        while (cents >= 25)
        {
            count += 1;
            cents -= 25;
        }
        // checks if cents is within 10s range
        while (cents >= 10)
        {
            count += 1;
            cents -= 10;
        }
        while (cents >= 5)
        {
            count += 1;
            cents -= 5;
        }
        while (cents >= 1)
        {
            count += 1;
            cents -= 1;
        }
        printf("%i\n", count);
    }
    while (change_owed <= 0);
}
