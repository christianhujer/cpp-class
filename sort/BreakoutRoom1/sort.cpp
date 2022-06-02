#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

static vector<string> vectorOfLines;

vector<string> sortVector(vector<string> &vectorOfLines)
{
    sort(vectorOfLines.begin(), vectorOfLines.end());
    return vectorOfLines;
}

void PrintVector(vector<string> &vectorOfLines)
{
    for (int i = 0; i < vectorOfLines.size(); i++)
    {
        cout << vectorOfLines[i] << endl;
    }
}

void getFileContent(string &filename)
{
    ifstream myfile(filename);
    string line;
    while (getline(myfile, line))
    {
        vectorOfLines.emplace_back(line);
    }
}

bool getStatus(int argc, string filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
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
        // cout << cin.rdbuf() << endl;
    }
    else
    {
        for (int i = 0; i < argc; i++)
        {
            string inputFileName = argv[i];
            bool result = getStatus(argc, inputFileName);
            if (result)
            {
                getFileContent(inputFileName);
            }
            else
            {
                endResult = EXIT_FAILURE;
            }
        }
        sortVector(vectorOfLines);
        PrintVector(vectorOfLines);
    }
    return endResult;
}