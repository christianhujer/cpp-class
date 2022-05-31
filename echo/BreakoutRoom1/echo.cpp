#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string echo(int argc, char *argv[]) {
    stringstream ss;
    for (int i = 1; i < argc; i++) {
        if (i > 1) 
            ss << " ";
        ss << argv[i];
    }
    ss << endl;
    return ss.str();
}

int main(int argc, char* argv[]) {
    cout << echo(argc, argv);
    return EXIT_SUCCESS;
}