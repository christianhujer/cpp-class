#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char *inputArgument)
{
    int firstIndex = 0;
    int length = strlen(inputArgument) - 1;
    while(firstIndex < length)
    {
        while (!isalnum(inputArgument[firstIndex]) && firstIndex < length)
            firstIndex++;
        while (!isalnum(inputArgument[length]) && firstIndex < length)
           length--;
        if (tolower(inputArgument[firstIndex++]) != tolower(inputArgument[length--]))
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
    assert(isPalindrome(input));
    strcpy(input, "foo");
    assert(!isPalindrome(input));
    strcpy(input, "AGA");
    assert(isPalindrome(input));
    strcpy(input, "Anna");
    assert(isPalindrome(input));
    strcpy(input, "Otto");
    assert(isPalindrome(input));
    strcpy(input, "Hildegard");
    assert(!isPalindrome(input));
    strcpy(input, "Vishnu");
    assert(!isPalindrome(input));
    strcpy(input, "a#a+aa");
    assert(isPalindrome(input));
    strcpy(input, "Amok Oma");
    assert(isPalindrome(input));
    strcpy(input, "A man, a plan, a canal: Panama");
    assert(isPalindrome(input));
    strcpy(input, "+");
    assert(isPalindrome(input));
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