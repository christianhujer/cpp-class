#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    stringstream s;
    for (int i = 1; i < argc; i++)
    {
        if (i == (argc - 1))
            s << argv[i];
        else {
            s << argv[i] << " ";
        }
    }  
    cout << s.str();
    return EXIT_SUCCESS;
}