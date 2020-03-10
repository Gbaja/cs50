#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);
int convertLetterToInt(char letter, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    // prints error if there is a number in argument
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]))
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }
    // ask user for string
    string plainText = get_string("plaintext: ");
    printf("ciphertext: ");
    // keeps track of position of keyword
    int j;
    for (int i = 0; i < strlen(plainText); i++)
    {
        // Check if its a letter
        if (isalpha(plainText[i]))
        {
            int key = shift(argv[1][j]);
            char letter = (char) plainText[i];
            char letterInt = (char) convertLetterToInt(letter, key);
            printf("%c", letterInt);
            j++;
            if (j == strlen(argv[1]))
            {
                j = 0;
            }
        }
        else
        {
            printf("%c", plainText[i]);
        }

    }
    printf("\n");
}

// Function that takes a character as an argument and returns the ascii number for the letter
// Checks if its upper or lower case
int shift(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 65;
    }
    // Check if its small letter
    else if (c >= 'a' && c <= 'z')
    {
        return c - 97;
    }
    else
    {
        return c;
    }
}

// Helper function to help change a letter using a key to the key's letter
int convertLetterToInt(char letter, int key)
{
    // Check if its capital letter
    if (letter >= 'A' && letter <= 'Z')
    {
        return (letter - 65 + key) % 26 + 65;
    }
    // Check if its small letter
    else if (letter >= 'a' && letter <= 'z')
    {
        return (letter - 97 + key) % 26 + 97;
    }
    else
    {
        return letter;
    }
}
