#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char *inputArgument)
{
    int n = 0;
    int length = strlen(inputArgument) - 1;
    while(n < length)
    {
        while (!isalnum(inputArgument[n]) && n < length)
            n++;
        while (!isalnum(inputArgument[length]) && n < length)
           length--;
        if (tolower(inputArgument[n++]) != tolower(inputArgument[length--]))
        {
            return false;
        } 
    }
    return true;
}

void selfTest()
{
    char* input = (char*)malloc(100*sizeof(char));
    strcpy(input, "");
    assert(isPalindrome(input) == 1);
    strcpy(input, "foo");
    assert(isPalindrome(input) == 0);
    strcpy(input, "AGA");
    assert(isPalindrome(input) == 1);
    strcpy(input, "Anna");
    assert(isPalindrome(input) == 1);
    strcpy(input, "Otto");
    assert(isPalindrome(input) == 1);
    strcpy(input, "Hildegard");
    assert(isPalindrome(input) == 0);
    strcpy(input, "Vishnu");
    assert(isPalindrome(input) == 0);
    strcpy(input, "a#a+aa");
    assert(isPalindrome(input) == 1);
    strcpy(input, "Amok Oma");
    assert(isPalindrome(input) == 1);
    strcpy(input, "A man, a plan, a canal: Panama");
    assert(isPalindrome(input) == 1);
}

int main(int argc, char* argv[])
{
    selfTest();
    bool endResult = EXIT_SUCCESS;
    for (int i = 1; i < argc; i++)
    {
        char *inputargument = argv[i];
        if (isPalindrome(inputargument))
        {
            printf("%s is a palindrome\n", inputargument);
        }
        else
        {
            printf("%s is not a palindrome\n", inputargument);
            endResult = EXIT_FAILURE;
        }
    }
    return endResult;
}