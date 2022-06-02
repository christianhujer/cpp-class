#include <iostream>

using namespace std;

int smallestMultiple()
{
    
    for (int i = 20; ; i++)
    {
        int check = 0;
        for (int j = 1; j < 21; j++)
        {
            if (i % j == 0)
            {
                check++;
            }
        }
        if (check == 20)
        {
            return i;
            break;
        }
       // check = 0;
    }
}

int main()
{
    cout << smallestMultiple() << endl;
    return EXIT_SUCCESS;
}