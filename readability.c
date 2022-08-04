#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

string upper(string text);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    string text = get_string("Text: ");
    text = upper(text);


    float L = count_letters(text) / (float) count_words(text) * 100;
    float S = count_sentences(text) / (float) count_words(text) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        if (index > 16)
        {
            printf("Grade 16+\n");
        }

        else
        {
            printf("Grade %i\n", index);
        }
    }


}

string upper(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        text[i] = toupper(text[i]);
    }

    return text;
}



int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] > 64 && text[i] < 91)
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }

    return words;
}


int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            sentences++;
        }
    }

    return sentences;
}
