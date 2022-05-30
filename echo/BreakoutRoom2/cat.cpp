//
// Created by shawm on 30-05-2022.
//
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    stringstream buffer;
    for (int i = 1; i < argc; i++) {
//        char data[100];

        ofstream outfile;
        outfile.open("cat.txt");
        buffer << argv[i];
        if (i < (argc-1))
            buffer << " ";

//        cout << "Writing to the file" << endl;
//        cout << "Enter your name: ";
//        cin.getline(data, 100);
//        outfile << data << endl;
    }
    buffer << endl;
    cout << buffer.str();
}