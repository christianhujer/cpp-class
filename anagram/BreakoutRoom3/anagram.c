#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sortString(char *argument)
{
    int length = strlen(argument);
    char temp;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (argument[i] > argument[j])
            {
                temp = argument[i];
                argument[i] = argument[j];
                argument[j] = temp;
            }
        }
    }
    return argument;
}

bool isAnagram(char *firstArgument, char *secondArgument)
{
    if (strlen(firstArgument) != strlen(secondArgument))
    {
        return false;
    }
    char *temp1 = (char*)malloc(sizeof(char));
    char *temp2 = (char*)malloc(sizeof(char));
    strcpy(temp1, firstArgument);
    strcpy(temp2, secondArgument);
    temp1 = sortString(temp1);
    temp2 = sortString(temp2);

    for (int i = 0; i < strlen(temp1); i++)
    {
        if (temp1[i] != temp2[i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    bool endResult = EXIT_SUCCESS;
    char *firstArgument = argv[1];
    char *secondArgument = argv[2];
    if (isAnagram(firstArgument, secondArgument))
    {
        printf("%s is a anagram of %s\n", argv[1], argv[2]);
    }
    else
    {
        printf("%s is not a anagram of %s\n", argv[1], argv[2]);
        endResult = EXIT_FAILURE;
    }
    return endResult;
}