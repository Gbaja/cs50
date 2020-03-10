#include <cs50.h>
#include <stdio.h>

int get_height(string prompt);
void make_hash(int height);

int main(void)
{
    // the number user enters for pyramid
    int num = get_height("Height: ");
    make_hash(num);
}

// Helper function for asking user for number
int get_height(string prompt)
{
    int height;
    do
    {
        //The height entered
        height = get_int("%s", prompt);
    }
    while (height < 1 || height > 8);
    return height;
}

//Helper function for drawing pyramid
void make_hash(int height)
{
    for (int i = 1; i <= height; i++)
    {
        for (int k = 1; k <= height - i; k++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
