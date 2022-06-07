#include <iostream>

using namespace std;

void dash(const char *str);

void dash(const char *str)
{
    while (*str)
    {
        if (*str == ' ')
            cout << "-";
        else
            cout << *str;
        str++;
    }
}


int main()
{
    dash("this is a string");
    // cout << endl;
    // cout << dash("another string");
    return 0;
}