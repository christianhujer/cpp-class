#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    int exitStatus = EXIT_SUCCESS;
    if (argc == 1)
        cout << cin.rdbuf();
    for (int i = 1; i < argc; i++)
    {
        ifstream infile;
        infile.open(argv[i]);
        if (infile.is_open())
        {
            cout << infile.rdbuf();
        }
        else
        {
            cerr << "cat: " << argv[i] << " : No such file or directory" << endl;
            exitStatus = EXIT_FAILURE;
        }
        infile.close();
    }
    return exitStatus;
}