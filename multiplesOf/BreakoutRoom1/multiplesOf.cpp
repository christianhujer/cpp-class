#include <iostream>

using namespace std;

int multipleOf(){
    int num = 0, i = 0;
    while (i < 1000)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
        {
            num = num + i;
        }
        i++;
    }
    return num;
}

int main(void)
{
    int result;
    result =multipleOf();
    cout << result << endl;
    return EXIT_SUCCESS;
}