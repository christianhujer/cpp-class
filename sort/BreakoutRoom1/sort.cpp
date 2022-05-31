#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> sortVector(vector<vector<string>> &vectorOfLines)
{
    sort(vectorOfLines.begin(), vectorOfLines.end());
    return vectorOfLines;
}

void PrintVector(vector<vector<string>> &vectorOfLine)
{
    sortVector(vectorOfLine);
    for (int i = 0; i < vectorOfLine.size(); i++)
    {
        for (int j = 0; j < vectorOfLine[i].size(); j++)
        {
            cout << vectorOfLine[i][j] << endl;
        }
    }
}

vector<string> getFileContent(string &filename)
{
    vector<string> vectorOfLines;
    ifstream myfile(filename);
    string line;
    while(getline(myfile, line))
    {
        vectorOfLines.emplace_back(line);
    }
    return vectorOfLines;
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

int main(int argc, char* argv[])
{
    bool endResult = EXIT_SUCCESS;
    vector<vector<string>> vectorOfAllLines;
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
            if(result)
            {
                vectorOfAllLines.emplace_back(getFileContent(inputFileName));
            }
            else
            {
                endResult = EXIT_FAILURE;
            }
        }
        PrintVector(vectorOfAllLines);
    }
    return endResult;
}