#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    stringstream buffer;
    for (int i = 1; i < argc; i++) {
        buffer << argv[i];
        if (i < (argc-1))
            buffer << " ";
    }
    buffer << endl;
    cout << buffer.str();
    return EXIT_SUCCESS;
}