#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 1) {
        cout << endl;
        return EXIT_SUCCESS;
    }
    string str;
    if (argc > 1) {
        getline(cin,str);
    }
}