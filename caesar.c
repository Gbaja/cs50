#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check it only has two arguments
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    // Loop through the second argument to check that it only contains numbers
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }
    // convert the string argument to number
    int key = atoi(argv[1]);
    string plainText = get_string("plaintext: ");
    // Loop through the letter
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plainText); i++)
    {
        // Check if its capital letter
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            printf("%c", ((plainText[i] - 65 + key) % 26 + 65));
        }
        // Check if its small letter
        else if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            printf("%c", ((plainText[i] - 97 + key) % 26 + 97));
        }
        else
        {
            printf("%c", plainText[i]);
        }

    }
    printf("\n");
    return 0;
}
