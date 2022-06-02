#include <iostream>
#include <cassert>

using namespace std;

int largestPrimeFactor(long long int number)
{
    int largestFactor = 0;
    for (int i = 2; number != 1; i++)
    {
        while(number % i == 0)
        {
            number /= i;
            largestFactor = i;
        }
    }
    return largestFactor;
}

void selfTest()
{
    assert(largestPrimeFactor(6) == 3);
    assert(largestPrimeFactor(13195) == 29);
    assert(largestPrimeFactor(50) == 5);
}

int main()
{
    selfTest();
    long long int number = 600851475143;
    cout << largestPrimeFactor(number) << endl;
    return EXIT_SUCCESS;
}