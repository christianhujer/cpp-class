#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void printData(vector<string> &fileData)
{
     for (int i = 0; i < fileData.size(); i++)
    {
        cout << fileData[i] << endl;
    }
}

void getContent(string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << filename << " does not exist" << endl;
    }
    vector <string> fileData;
    string word;
    while (file >> word)
    {
        fileData.emplace_back(word);
    }
    for (auto i = fileData.begin(); i != fileData.end(); i++)
    {
        for (auto j = i->begin(); j != i->end(); j++)
        {
            *j = tolower(*j);
        }
    }
} 

int main(int argc, char* argv[])
{
    bool status = EXIT_SUCCESS;
    for (int i = 1; i < argc; i++)
    {
        string inputFileName = argv[i];
        getContent(inputFileName);
    }
    return status;
}