#include <iostream>

using namespace std;

int lcmOfTwo(int x, int y)
{
    int max;
    max = (x > y) ? x : y;

    while (true)
    {
        if ((max % x == 0) && (max % y == 0))
            return max;
        ++max;
    }
}

int smallestMultiple(int range[])
{
    int result = range[0];
    for (int i = 0; i < 20; i++)
        result = lcmOfTwo(result, range[i]);
    return result;
}

int main(void)
{
    int numberRange[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    cout << smallestMultiple(numberRange) << endl;
    return EXIT_SUCCESS;
}