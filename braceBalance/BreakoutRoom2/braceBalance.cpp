#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <stack>

using namespace std;

bool isInList(char word, list<char> braces)
{
    list<char>::iterator it;
    for (it = braces.begin(); it != braces.end(); it++)
    {
        if (word == *it)
            return true;
    }
    return false;
}

bool isOpening(char word)
{
    list<char> braces = {'(', '[', '{'};
    if (isInList(word, braces))
        return true;
    return false;
}

bool isClosing(char word)
{
    list<char> braces = {')', ']', '}'};
    if (isInList(word, braces))
        return true;
    return false;
}

bool isMatching(char open, char close)
{
    map<char, char> braces = {{'(', ')'},
                              {'[', ']'},
                              {'{', '}'}};
    //cout << "|" << open << "," << close << "|" << endl;
    if (braces[open] == close)
        return true;
    else
    {
        cout << braces[open] << " is expected." << endl;
        return false;
    }
}

bool isBraceBalance(string &filename)
{
    ifstream file(filename);
    bool status = true;
    if (!file.is_open())
    {
        cout << filename << " does not exists." << endl;
        status = false;
    }
    char word;
    stack<char> openingBraces;
    while (file.get(word))
    {
        if (isOpening(word))
            openingBraces.push(word);
        if (isClosing(word))
        {
            if (!openingBraces.empty())
            {
                if (!isMatching(openingBraces.top(), word))
                    status = false;
            }
            else
            {
                cout << word << " is unexpected." << endl;
                status = false;
            }
            openingBraces.pop();
        }
    }
    while(!openingBraces.empty()){
        if (!isMatching(openingBraces.top(), '<'))
                    status = false;
        openingBraces.pop();
    }
    return status;
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