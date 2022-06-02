#include <iostream>

using namespace std;

bool isprime(int factor){
    for (int i = 2; i <= factor/2; i++)
    {
        if(factor % i != 0)
            continue;
        else
        return false;
    }
    return true;
}

long long largestPrimeFactor(long long inputNumber) {
    long long largestPrimeFactor = 0;
    for (int factor = 2; inputNumber != 1; factor++) {
        if(inputNumber % factor == 0 && isprime(factor)){
            inputNumber /= factor;
            largestPrimeFactor = factor;
        }
    }
    return largestPrimeFactor;
}

int main() {
    long long inputNumber = 600851475143;
    cout << "Largest prime factor of " << inputNumber <<" is: " << largestPrimeFactor(inputNumber) << endl;
    return EXIT_SUCCESS;
}

