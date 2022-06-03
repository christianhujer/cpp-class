#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

vector<char> braces = {'(', ')', '{', '}', '[', ']'};

bool isInList(char word)
{
    vector<char>::iterator it;
    for (it = braces.begin(); it != braces.end(); it++)
    {
        if (word == *it)
            return true;
    }
    return false;
}

bool isBalanced(vector<char> &bracesInFile)
{
    bool status = true;   
    for (int i = 0; i < 5; i += 2)
    {
        int count1 = count(bracesInFile.begin(), bracesInFile.end(), braces[i]);
        int count2 = count(bracesInFile.begin(), bracesInFile.end(), braces[i+1]);
        if (count1 == count2)
        {
            status;
        }
        else if (count1 > count2)
        {
            cerr << "error: missing '" << braces[i+1] << "'" << endl;
            status = false;
        }
        else
        {
            cerr << "error: missing '" << braces[i] << "'" << endl;
            status = false;
        }
    }
    return status;
}

bool isBraceBalance(string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << filename << " does not exists" << endl;
        return false;
    }
    char word;
    vector<char> bracesInFile;
    while (file.get(word))
    {
        if (isInList(word))
        {
            bracesInFile.emplace_back(word);
        }
    }
    if (isBalanced(bracesInFile))
        return true;
    return false;
}

int main(int argc, char *argv[])
{
    bool status = EXIT_SUCCESS;
    for (int i = 1; i < argc; i++)
    {
        string filename = argv[i];
        if (!isBraceBalance(filename))
            status = EXIT_FAILURE;
    }
    return status;
}