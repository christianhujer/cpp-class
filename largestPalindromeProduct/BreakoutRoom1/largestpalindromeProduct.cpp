#include <iostream>

using namespace std;

bool isPalindrome(int multiplication)
{
    int reverse = 0;
    int old = multiplication;
    while (multiplication > 0)
    {
        int temprory;
        temprory = (multiplication % 10);
        reverse = (reverse * 10) + temprory;
        multiplication /= 10;
    }
    return reverse == old;
}

int largestPalindromeProduct()
{
    int largestPalindromeProduct = 0;
    for (int i = 100; i < 1000; i++)
    {
        for (int j = 100; j < 1000; j++)
        {
            int multiplication = i * j;
            if (isPalindrome(multiplication) && multiplication > largestPalindromeProduct)
            {
                largestPalindromeProduct = multiplication;
            }
        }
    }
    return largestPalindromeProduct;
}

int main()
{
    cout << "largest palindrome product- " << largestPalindromeProduct();
}