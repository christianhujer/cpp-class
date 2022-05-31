#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void concatenateFileContent(int argc, string filename)

{
    ifstream myfile(filename.c_str());

    if (myfile.is_open())
    {
        string str;
        vector<string> vectstr;
        while (getline(myfile, str))
        {
            if (str.size() > 0)
                vectstr.push_back(str);
        }
        sort(vectstr.begin(), vectstr.end());
        for (auto i : vectstr)
        {
            cout << i << endl;
        }
    }
    else
    {

        cerr << filename << " does not exist";
    }
    myfile.close();
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

            concatenateFileContent(argc, inputFileName);
        }
    }
    return EXIT_SUCCESS;
}
