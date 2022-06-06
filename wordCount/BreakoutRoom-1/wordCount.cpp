#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

bool wordCount(string filename)
{
    ifstream input(filename);
    if (!input)
    {
        cout << "Error opening data file " << filename << "\n";
        return 1;
    }
    map<string, unsigned int> word_data;
    string word;
    while (input >> word)
    {
        if (word_data.find(word) != word_data.end())
        {
            word_data[word]++;
        }
        else
        {
            word_data[word] = 1;
        }
    }
    map<string, unsigned int>::iterator it;
    for (it = word_data.begin(); it != word_data.end(); ++it)
    {
        cout << it->second << " " << it->first << "\n";
    }
}

int main(int argc, char *argv[])
{
    bool exitStatus = EXIT_SUCCESS;
    for (int i = 1; i < argc; i++)
    {
        string filename = argv[1];
        if(!wordCount(filename))
        exitStatus = EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}