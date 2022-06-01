#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeNoise(char *word) {
    
    int len = 0;  
    len = sizeof(word)/sizeof(word[0]);
    for (int i = 0; i < len; i++){
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
    printf("%s\n",word);
    return word;
}

char* invert(char *word) {
    char *invertedWord;
}

bool isPlaindrome(char *word) {
    word = removeNoise(word);
    return word == invert(word);
}

void test() {
    assert(strcmp(removeNoise("Amok Oma"),"amokoma"));
    assert(strcmp(removeNoise("Amok Oma"),"amo ikoma"));
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
