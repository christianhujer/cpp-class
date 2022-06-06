#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void printData(vector<string> &fileData)
{
    vector<string>uniqueData = fileData;
    uniqueData.erase( unique( uniqueData.begin(), uniqueData.end() ), uniqueData.end() );
    for (auto it = uniqueData.begin(); it != uniqueData.end(); it++){
        string str = *it;
        int frequency = count(fileData.begin(), fileData.end(), str);
        cout << str<< " " << frequency <<endl;
    }
}

void removePunch(vector<string> &fileData)
{
    for (auto i = fileData.begin(); i != fileData.end(); i++)
    {
        string str = *i;
        auto it = std::remove_if(str.begin(), str.end(), [](char const &c) { return std::ispunct(c); });
        str.erase(it, str.end());
        *i = str;
    }
}

void toLower(vector<string> &fileData)
{
    for (auto i = fileData.begin(); i != fileData.end(); i++)
    {
        for (auto j = i->begin(); j != i->end(); j++)
        {
            *j = tolower(*j);
        }
    }
}

bool getContent(string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << filename << " does not exist" << endl;
        return false;
    }
    vector<string> fileData;
    string word;
    while (file >> word)
    {
        fileData.emplace_back(word);
    }
    toLower(fileData);
    removePunch(fileData);
    sort(fileData.begin(), fileData.end());
    printData(fileData);
    return true;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        string inputFileName = argv[i];
        getContent(inputFileName);
    }
    return EXIT_SUCCESS;
}