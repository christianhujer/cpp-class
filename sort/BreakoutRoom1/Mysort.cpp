#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

static vector<string> vectOfStrings;

void fileContent(int argc, string filename)
{
    ifstream myfile(filename.c_str());
    if (myfile.is_open())
    {
        string data;
        while (getline(myfile, data))
        {
            vectOfStrings.push_back(data);
        }
    }
    else
        cerr << filename << " does not exist";
    myfile.close();
}

vector<string> sortVector(vector<string> &vectOfStrings)
{
    sort(vectOfStrings.begin(), vectOfStrings.end());
    return vectOfStrings;
}

void printVector(vector<string> &vectOfStrings)
{
    for (int i = 0; i < vectOfStrings.size(); i++)
        cout << vectOfStrings[i] << endl;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << cin.rdbuf();
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            string inputFileName = argv[i];
            fileContent(argc, inputFileName);
        }
        sortVector(vectOfStrings);
        printVector(vectOfStrings);
    }
    return EXIT_SUCCESS;
}