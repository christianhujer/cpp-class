#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{

    if (argc == 1) {
        while (true)
        {
            string str;
            getline(cin, str);
            cout << str << endl;
        }
    }
    for (int i = 1; i < argc; i++)
    {
        ifstream istream;
        istream.open(argv[i]);
        if (!istream)
        {
            cerr << "Failed to open file";
            return EXIT_FAILURE;
        }
        while (istream.eof() == 0)
        {
            string s;
            getline(istream, s);
            cout << s << endl;
        }
    }
    return EXIT_SUCCESS;
}
