#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sortWord(char *word)
{
    char temprory;
    int n = strlen(word);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (word[i] > word[j])
            {
                temprory = word[i];
                word[i] = word[j];
                word[j] = temprory;
            }
        }
    }
    return word;
}

int main(int argc, char *argv[])
{
    bool endresult = EXIT_SUCCESS;

    char *firstWord = (char *)malloc(sizeof(char));
    char *secondWord = (char *)malloc(sizeof(char));
    strcpy(firstWord, argv[1]);
    strcpy(secondWord, argv[2]);

    if (strlen(firstWord) != strlen(secondWord))
    {
        printf("%s is not an anagram of %s", argv[1], argv[2]);
        endresult = EXIT_FAILURE;
    }
    else
    {
        if (strcmp(sortWord(firstWord), sortWord(secondWord)) == 0)
            printf("%s is an anagram of %s", argv[1], argv[2]);

        else
        {
            printf("%s is not an anagram of %s", argv[1], argv[2]);
            endresult = EXIT_FAILURE;
        }
    }

    free(firstWord);
    free(secondWord);

    return endresult;
}
