#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeNoise(char *word) {
    
    int len = 0;
    len = strlen(word);
    for (int i = 0; i < len; i++) {
        word[i] = tolower(word[i]);
    }
    for (int i = 0; i < len; i++){  
        if (word[i] == ' '){  
            for (int j = i; j < len; j++)  
        {  
            word[j] = word[j + 1];  
        }  
        len--;  
        }  
    }
    return word;
}

char* invert(char *word) {
    char *invertedWord = malloc((size_t) 30);
    int len = strlen(word) - 1;
    for (int i = 0; i < strlen(word); i++) {
        invertedWord[i] = word[len--]; 
    }
    invertedWord[strlen(word)] = '\0';
    return invertedWord;
}

bool isPlaindrome(char *word) {
    word = removeNoise(word);
    if (strcmp(word,invert(word)) == 0) {
        printf("%s is a palindrome\n",word);
        return true;
    }
    else {
         printf("%s is not a palindrome\n",word);
         return false;
    }
}

void test() {
    char *testWord = malloc((size_t) 100);
    strcpy(testWord,"Amok oma");
    assert(strcmp(removeNoise(testWord),"amokoma") == 0);
    assert(strcmp(invert(testWord),"amokoma") == 0);
}

int main(int argc, char *argv[]) {
    test();
 
    bool status = EXIT_SUCCESS;
    for (int i = 1; i < argc; i++) {
        if (!isPlaindrome(argv[i])) {
            status = EXIT_FAILURE;
        }
    }
    return status;
}
