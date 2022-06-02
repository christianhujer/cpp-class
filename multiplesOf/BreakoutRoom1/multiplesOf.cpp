#include <iostream>

using namespace std;

int main(void)
{
    int num = 0, i = 0;
    while (i < 1000)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            num = num + i;
        }
        i++;
    }
    cout << num << endl;
    return EXIT_SUCCESS;
}