#include <iostream>

using namespace std;

int SumOfMultiples(int a, int b)
{
     int Sum = 0;
     for(int i = 1; i<1000; i++)
     {
         if((i%3 ==0) || (i%5 == 0))
         {
            Sum = Sum + i;
         }
     }
     return Sum;
}

int main()
{
    int result = SumOfMultiples(3,5);
    printf("%d sum of multiple of 3 and 5 ",result);
    return EXIT_SUCCESS;

}