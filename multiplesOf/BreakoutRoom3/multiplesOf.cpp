#include <iostream>

using namespace std;

long long sumOfSeries(int number, int divisor)
{
    number /= divisor;
    return number * (1 + number) * divisor / 2;
}

int sumOfMultiples(int number)
{
    number--;
    return sumOfSeries(number, 3) + sumOfSeries(number , 5) - sumOfSeries(number, 15);
}

int main()
{
    int number = 1000;
    cout << sumOfMultiples(number) << endl;
    return EXIT_SUCCESS;
}