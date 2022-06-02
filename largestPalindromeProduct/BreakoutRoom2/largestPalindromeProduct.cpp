#include <iostream>

using namespace std;

bool isProductPalindrome(int product)
{
    int revNumber = 0;
    int orignalNumber = product;
    while (product != 0)
    {
        revNumber = (revNumber * 10) + (product % 10);
        product /= 10;
    }
    return revNumber == orignalNumber;
}

int largestPalindromeProduct()
{
    int largestPalindromeProduct = 0;
    for (int first = 100; first <= 999; first++)
    {
        for (int second = 100; second <= 999; second++)
        {
            int product = first * second;
            if (isProductPalindrome(product) && product > largestPalindromeProduct)
            {
                largestPalindromeProduct = product;
            }
        }
    }
    return largestPalindromeProduct;
}

int main()
{
    cout << "largest 3 digit palindrome product " << largestPalindromeProduct();
}