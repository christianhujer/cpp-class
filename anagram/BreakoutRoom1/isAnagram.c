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

bool isAnagram(char* firstname, char* secondname)
{

    if (strlen(firstname) != strlen(secondname))
    {
         return 0;
    }
    else
    {
        if (strcmp(sortWord(firstname), sortWord(secondname)) == 0)
        {
            return 1;
        }
        else
        {
           return 0;
        }
    }

}

int main(int argc, char *argv[])
{
    bool endresult = EXIT_SUCCESS;
     char *FirstOriginal = (char *)malloc(sizeof(char));
    char *SecondOriginal = (char *)malloc(sizeof(char));
    strcpy(FirstOriginal, argv[1]);
    strcpy(SecondOriginal, argv[2]);

    if(isAnagram(argv[1], argv[2]))
    {
        printf("%s is an anagram of %s", FirstOriginal, SecondOriginal);
    }
    else{
        printf("%s is not an anagram of %s", FirstOriginal, SecondOriginal);
        endresult = EXIT_FAILURE;
    }
    free(FirstOriginal);
    free(SecondOriginal);

    return endresult;
}
