#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letter(string letter);
int count_words(string word);
int count_sentence(string sentence);

int main(void)
{
    int grade;
    double index, L, S;
    string text = get_string("Text: ");

    int letter = count_letter(text);
    int words = count_words(text);
    int sentence = count_sentence(text);

    L = letter * 100 / words;
    S = sentence * 100 / words;
    index = 0.0588 * L - 0.296 * S - 15.8;

    printf("index=%f ", index);
    printf("amari=%f\n", fmod(index, 1));

    if (fmod(index, 1) < 0.55) //四捨五入もどき
    {
        grade = (int)index;
    }
    else
    {
        grade = (int)index + 1;
    }
    // printf("index= %d\n",grade);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (1 <= grade && grade < 17)
    {
        printf("Grade %d\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }

    return 0;
}

// 入力されたテキストの文字数を数える
int count_letter(string text)
{
    int i, count;
    i = 0;
    count  = 0;
    while (text[i])
    {
        if (text[i] == '-' || text[i] == '\'' || text[i] == ':' || text[i] == ';' || text[i] == ',' || text[i] == '.' || text[i] == '!'
            || text[i] == '?' || text[i] == ' ')
        {
            count--; //記号はletterに含めない
        }
        i++;
        count++;
    }
    // printf("letter=%d\n", count);
    return count;
}

// 入力されたテキストの単語数を数える
int count_words(string text)
{
    int i, count;
    i = 0;
    count  = 0;

    while (text[i])
    {
        if (text[i] == ' ')
        {
            count++;
        }
        i++;
    }
    // printf("words=%d\n", count+1);
    return count + 1;
}

// 入力されたテキストの文章の数を数える
int count_sentence(string text)
{
    int i, count;
    i = 0;
    count  = 0;

    while (text[i])
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
        i++;
    }
    // printf("sentence=%d\n", count);
    return count;
}