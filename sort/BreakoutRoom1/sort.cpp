#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void sortVector(vector<string> &vectorOfLines)
{
    sort(vectorOfLines.begin(), vectorOfLines.end());
}

void PrintVector(vector<string> &vectorOfLines)
{
    for (int i = 0; i < vectorOfLines.size(); i++)
    {
        cout << vectorOfLines[i] << endl;
    }
}

vector<string> getFileContent(string &filename)
{
    vector<string> vectorOfLine;
    ifstream myfile(filename);
    string line;
    while (getline(myfile, line))
    {
        vectorOfLine.emplace_back(line);
    }
    return vectorOfLine;
}

bool getStatus(string &filename)
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
            if (getStatus(inputFileName))
            {
               vector<string> tempVector = getFileContent(inputFileName);
               for (int j = 0; j < tempVector.size(); j++)
               {
                   vectorOfAllLines.emplace_back(tempVector[j]);
               }
            }
            else
            {
                endResult = EXIT_FAILURE;
            }
        }
        sortVector(vectorOfAllLines);
        PrintVector(vectorOfAllLines);
    }
    return endResult;
}