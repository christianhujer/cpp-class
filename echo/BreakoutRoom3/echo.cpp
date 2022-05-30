#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string concatenateArguments(int argc, char *argv[])
{
    stringstream ss;
    for (int i = 1; i < argc; i++)
    {
        ss << argv[i] << " ";
    }
    return ss.str();
}

int main(int argc, char *argv[])
{
    string concatenateResult = concatenateArguments(argc, argv);
    cout << concatenateResult << endl;
    return EXIT_SUCCESS;
}