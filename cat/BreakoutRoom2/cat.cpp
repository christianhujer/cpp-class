//
// Created by shawm on 30-05-2022.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{

    if (argc == 1)
        while (true)
        {
            string str;
            getline(cin, str);
            cout << str << endl;
        }

    for (int i = 1; i < argc; i++)
    {

        string a;
        ifstream infile;

        infile.open(argv[i]);
        if (!infile)
        {
            cerr << "cat: " << argv[i] << " : No such file or directory" << endl;
        }
        else
        {
            // getline(infile, a);

            streambuf *psbuf, *backup;

            backup = cout.rdbuf();

            psbuf = infile.rdbuf();
            cout.rdbuf(psbuf);

            cout << cout.rdbuf(backup) << endl;

            infile.close();
        }
    }
    // return EXIT_SUCCESS;
}