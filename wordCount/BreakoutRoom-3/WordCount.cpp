#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

string lowercase(string convertString)
{
    int ln = convertString.length();
    for (int i = 0; i < ln; i++)
    {
        if (convertString[i] >= 'A' && convertString[i] <= 'Z')
            //convertString[i] = convertString[i] + 32;
            convertString[i] = tolower(convertString[i]);
    }
    return convertString;
}

void word_count(string &filename, bool *exit_status)
{

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "file doesnot exist" << endl;
        *exit_status = false;
    }

    char word;
    map<string, int> Counters;
    string s;

    while (file.get(word) >> s)
    {
        for (int i = 0, len = s.size(); i < len; i++)
        {
            if (ispunct(s[i]))
            {
                s.erase(i--, 1);
                len = s.size();
            }
        }
        s = lowercase(s);
        ++Counters[s];
    }

    for (map<string, int>::const_iterator it = Counters.begin(); it != Counters.end(); ++it)
    {
        cout << it->first << "\t" << it->second << endl;
    }
}

int main(int argc, char *argv[])
{
    bool exit_status = true;
    for (int i = 1; i < argc; i++)
    {
        string filename = argv[i];
        word_count(filename, &exit_status);
    }
    if (exit_status)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}