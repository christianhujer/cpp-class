#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void sortAndPrintvector(vector<string> &vectorOfline)
{
    sort(vectorOfline.begin(), vectorOfline.end());
    for (int i = 0; i < vectorOfline.size(); i++)
    {
        cout << vectorOfline[i] << endl;
    }
}

void getcontent(int argc, string file)
{
    vector<string> vectorOfLines;
    ifstream in(file.c_str());
    if (!in)
    {
        cerr << "Cannot open the File : " << file << endl;
    }

    string line;
    while (getline(in, line))
    {
        if (line.size() > 0)
            vectorOfLines.emplace_back(line);
    }
    sortAndPrintvector(vectorOfLines);
    in.close();
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << cin.rdbuf();
    }
    else
    {
        for (int i = 0; i < argc; i++)
        {
            string inputFileName = argv[i];
            getcontent(argc, inputFileName);
        }
    }
    return EXIT_SUCCESS;
}