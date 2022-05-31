#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void concatenateFileContent(int argc, string filename)
{
    ifstream myfile(filename.c_str());
    if (myfile.is_open())
    {
        cout << myfile.rdbuf();
    }
    else
    {
        cerr << filename << " does not exist\n";
    }
    myfile.close();
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << cin.rdbuf();
    }
    for (int i = 1; i < argc; i++)
    {
        string inputFileName = argv[i];
        concatenateFileContent(argc, inputFileName);
    }
    return EXIT_SUCCESS;
}