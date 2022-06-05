#include <iostream>

using namespace std;

int smallestMultiple()
{
    int result;
    for (int i = 20; ; i++)
    {
        result = 0;
        for (int j = 1; j < 21; j++)
        {
            if (i % j == 0)
            {
                result++;
            }
        }
        if (result == 20)
        {
            return i;
            break;
        }
    }
}

int main(void)
{
    cout << smallestMultiple() << endl;
    return EXIT_SUCCESS;
}