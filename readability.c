#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int calculate_num_of_words(string lettersForWords);
int calculate_num_of_letters(string lettersForLetters);
int calculate_num_of_sentences(string lettersForSentences);

int main(void)
{
    string paragraph = get_string("Text: ");
    int num_of_words = calculate_num_of_words(paragraph);
    int num_of_letters = calculate_num_of_letters(paragraph);
    int num_of_sentences = calculate_num_of_sentences(paragraph);
    // Calculates L
    float l = ((float)num_of_letters / (float)num_of_words) * 100;
    // Calculates S
    float s = ((float)num_of_sentences / (float)num_of_words) * 100;
    // Uses round from math.h to round up index
    int index = round(0.0588 * l - 0.296 * s - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    printf("Grade %i\n", index);
}

// Calculates number of words in paragraph
int calculate_num_of_words(string lettersForWords)
{
    int count = 0;
    for (int i = 0; i < strlen(lettersForWords); i++)
    {
        if (lettersForWords[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

// Calculate number of letters in paragraph
int calculate_num_of_letters(string lettersForLetters)
{
    int count = 0;
    for (int i = 0; i < strlen(lettersForLetters); i++)
    {
        // Uses letters ascii code to count only for numbers
        if ((lettersForLetters[i] >= 65 && lettersForLetters[i] <= 90) || (lettersForLetters[i] >= 95 && lettersForLetters[i] <= 122))
        {
            count++;
        }
    }
    return count;
}

// Calculates number of sentences in paragraph
int calculate_num_of_sentences(string lettersForSentences)
{
    int count = 0;
    for (int i = 0; i < strlen(lettersForSentences); i++)
    {
        // Checks for when . or ! or ? is seen
        if (lettersForSentences[i] == '.' || lettersForSentences[i] == '!' || lettersForSentences[i] == '?')
        {
            count++;
        }
    }
    return count;
}
