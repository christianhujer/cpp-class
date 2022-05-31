#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> sortVector(vector<string> &vectorOfLines)
{
    sort(vectorOfLines.begin(), vectorOfLines.end());
    return vectorOfLines;
}

void PrintVector(vector<string> &vectorOfLine)
{
    for (int i = 0; i < vectorOfLine.size(); i++)
    {
        cout << vectorOfLine[i] << endl;
    }
}

void getFileContent(string &filename, vector<string> vectorOfAllLines)
{
    ifstream myfile(filename);
    string line;
    while (getline(myfile, line))
    {
        vectorOfAllLines.emplace_back(line);
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
    vector<string> vectorOfAllLines;
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
                getFileContent(inputFileName, vectorOfAllLines);
            }
            else
            {
                endResult = EXIT_FAILURE;
            }
        }
        vectorOfAllLines = sortVector(vectorOfAllLines);
        PrintVector(vectorOfAllLines);
    }
    return endResult;
}