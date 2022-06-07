#include <iostream>

using namespace std;

int isLargestPrimeFactor(long long int num){

    int largestPrimeFact = 0;
    for (int i = 2; num != 1; ++i) {
        while(num % i == 0){
            num /= i;
            largestPrimeFact = i;
        }
    }
    return largestPrimeFact;
}
int main(void){

    long long int num = 600851475143;
    cout<<isLargestPrimeFactor(num)<<endl;
    return EXIT_SUCCESS;

}
