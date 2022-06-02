#include <iostream>

using namespace std;

bool isPalindrome(int number)
{
    int temp = number;
    int remainder, reverse = 0;
    while (number > 0)
    {
        remainder = number % 10;
        reverse = reverse * 10 + remainder;
        number /= 10;
    }
    if (temp == reverse)
    {
        return true;
    }
    return false;
}

int largestProduct()
{
    int maxProduct = 0;
    for (int i = 100; i < 1000; i++)
    {
        for (int j = 100; j < 1000; j++)
        {
            if (isPalindrome(i * j) && i * j > maxProduct)
            {
                maxProduct = i * j;
            }
        }
    }
    return maxProduct;
}

int main()
{
    cout << largestProduct() << endl;
    return EXIT_SUCCESS;
}