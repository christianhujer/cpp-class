#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool getContent(int argc, string &filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        cout << file.rdbuf();
        return true;
    }
    else
    {
        cerr << filename << " does not exist" << endl;
        return false;
    }
}

int main(int argc, char *argv[])
{
    bool endResult = EXIT_SUCCESS;
    if (argc == 1)
    {
        cout << cin.rdbuf();
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            string inputFileName = argv[i];
            if (!getContent(argc, inputFileName))
            {
                endResult = EXIT_FAILURE;
            }
        }
    }
    return endResult;
}
