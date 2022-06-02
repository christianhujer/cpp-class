#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

int compare(const void *a, const void *b)
{
    return *(const char *)a - *(const char *)b;
}

bool isAnagram(char *firstargument, char *secondargument)
{
    
    char* orignalFirst = (char*)malloc(sizeof(char));
    strcpy(orignalFirst, firstargument);
    char* orignalSecond = (char*)malloc(sizeof(char));
    strcpy(orignalSecond, secondargument);

    qsort(firstargument, strlen(firstargument), sizeof(firstargument[0]), compare);
    qsort(secondargument, strlen(secondargument), sizeof(secondargument[0]), compare);

    if(strcmp(firstargument,secondargument) == 0)
    {
        printf("%s and %s strings are an anagram of each other.\n", orignalFirst, orignalSecond);
        return true;
    }
    else
    {
        printf("%s and %s strings are not anagram of each other.\n", orignalFirst, orignalSecond);
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