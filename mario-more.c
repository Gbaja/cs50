#include <cs50.h>
#include <stdio.h>

int prompt_user(void);
void draw_pyramid(int n);
void draw_right_pyramid(int n);

int main(void)
{
    prompt_user();
};

// Function to ask user for height and render pyramid
int prompt_user(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
        draw_pyramid(n);
    }
    while (n <= 0 || n > 8);
    return n;
}

// Function to draw pyramids with
void draw_pyramid(int height)
{
    // Loop through their height entered
    for (int i = 1; i <= height; i++)
    {
        // Loop through each height
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
