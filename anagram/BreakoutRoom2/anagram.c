#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

char *sort(char *string)
{
    int n = strlen(string);
    char temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (string[i] > string[j])
            {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
    return string;
}

bool isAnagram(char *firstargument, char *secondargument)
{
    
    char orignalFirst[10];
    strcpy(orignalFirst, firstargument);
    char orignalSecond[10];
    strcpy(orignalSecond, secondargument);

    firstargument = sort(firstargument);
    secondargument = sort(secondargument);

    if(strcmp(firstargument,secondargument) == 0)
    {
        printf("%s and %s strings are an anagram of each other.\n", orignalFirst,orignalSecond);
        return true;
    }
    else
    {
        printf("%s and %s strings are not anagram of each other.\n", orignalFirst,orignalSecond);
        return false;
    }
}

int main(int argc, char *argv[])
{
    
    if (isAnagram(argv[1], argv[2]))
    {
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}