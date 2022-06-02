#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool isInList(char word, list<char> &braces)
{
    list<char>::iterator it;
    for (it = braces.begin(); it != braces.end(); it++)
    {
        if (word == *it)
            return true;
    }
    return false;
}

bool isParanthesisBalanced(vector<char> &bracesInFile)
{
    int count1 = count(bracesInFile.begin(), bracesInFile.end(), '(');
    int count2 = count(bracesInFile.begin(), bracesInFile.end(), ')');
    if (count1 == count2)
    {
        return true;
    }
    else if (count1 > count2)
    {
        cerr << "error: missing ')' " << endl;
        return false;
    }
    else
    {
        cerr << "error: missing '(' " << endl;
        return false;
    }
}

bool isCurlysBalanced(vector<char> &bracesInFile)
{
    int count1 = count(bracesInFile.begin(), bracesInFile.end(), '{');
    int count2 = count(bracesInFile.begin(), bracesInFile.end(), '}');
    if (count1 == count2)
    {
        return true;
    }
    else if (count1 > count2)
    {
        cerr << "error: missing '}' " << endl;
        return false;
    }
    else
    {
        cerr << "error: missing '{' " << endl;
        return false;
    }
}

bool isRectangularsBalanced(vector<char> &bracesInFile)
{
    int count1 = count(bracesInFile.begin(), bracesInFile.end(), '[');
    int count2 = count(bracesInFile.begin(), bracesInFile.end(), ']');
    if (count1 == count2)
    {
        return true;
    }
    else if (count1 > count2)
    {
        cerr << "error: missing ']'" << endl;
        return false;
    }
    else
    {
        cerr << "error: missing '[' " << endl;
        return false;
    }
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
    list<char> braces = {'(', ')', '{', '}', '[', ']'};
    vector<char> bracesInFile;
    while (file.get(word))
    {
        if (isInList(word, braces))
        {
            bracesInFile.emplace_back(word);
        }
    }
    if (isRectangularsBalanced(bracesInFile) && isParanthesisBalanced(bracesInFile) && isCurlysBalanced(bracesInFile))
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