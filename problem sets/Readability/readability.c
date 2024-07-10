#include <stdio.h>
#include "cs50.h"
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calculate_coleman_liau_index(int letters, int words, int sentences);

int main(void)
{
    // prompt the user for some text
    string text = get_string("Text: ");
    //count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // compute the coleman-liau index
    float index = calculate_coleman_liau_index(letters, words, sentences);
    // print the grade level
    if(index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int)round(index));
    }

}

int count_letters(string text)
{
    // return the number of letters
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    // return the number of words
    int count = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    // return the number of sentences
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

}
float calculate_coleman_liau_index(int letters, int words, int sentences)
{
    float L = (float) letters / words * 100;
    float S = (float)sentences / words * 100;

    return 0.0588 * L - 0.296 * S - 15.8;
}