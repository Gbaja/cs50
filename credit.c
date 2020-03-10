#include <stdio.h>
#include <cs50.h>
#include <math.h>

int check_sum(long long n);
int number_of_digits(long long n);
int counter;

int main(void)
{
    long long amex_divider = 10000000000000;
    long long mastercard_divider = 100000000000000;
    long long visa_divider_one = 1000000000000000;
    long long visa_divider_two = 1000000000000;

    long long credit_card_number;
    do
    {
        credit_card_number = get_long_long("Credit card number: ");
        int sum = check_sum(credit_card_number) % 10;
        if (sum == 0)
        {
            counter = number_of_digits(credit_card_number);
            if (counter == 15 && ((credit_card_number / amex_divider) == 34 || (credit_card_number / amex_divider) == 37))
            {
                printf("AMEX\n");
            }
            else if (counter == 16 && ((credit_card_number / mastercard_divider) >= 51 && (credit_card_number / mastercard_divider) <= 55))
            {
                printf("MASTERCARD\n");
            }
            else if ((counter == 16 && (credit_card_number / visa_divider_one) == 4) || (counter == 13
                     && (credit_card_number / visa_divider_two) == 4))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    while (credit_card_number <= 0);
}
//1234567890
//4111111111111113
int check_sum(long long card_number)
{
    // Variable to add all the values that are to be multiplied to
    int multiplication = 0;

    // Variable to add all the values that are to be added
    int addition = 0;

    // Loop through while the card number entered is greater 0
    while (card_number > 0)
    {
        int toBeMultiplied = 2 * ((card_number % 100) / 10);
        int toBeAdded = ((card_number % 100) % 10);
        if (toBeMultiplied > 9)
        {
            multiplication = multiplication + toBeMultiplied % 10 + 1;
        }
        else
        {
            multiplication += toBeMultiplied;
        }
        addition = addition + toBeAdded ;
        card_number /= 100;
    }
    return multiplication + addition;
}

int number_of_digits(long long number)
{
    int count = 0;
    while (number != 0)
    {
        number /= 10;
        ++count;
    }
    return count;
}
