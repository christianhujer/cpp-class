#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

bool word_count(string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "file doesnot exist" << endl;
        return EXIT_FAILURE;
    }
    char word;
    vector<string> wordsvector;
    while (file.get(word))
    {
        wordsvector.emplace_back(tolower(word));
    }
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        string filename = argv[i];
    }
}