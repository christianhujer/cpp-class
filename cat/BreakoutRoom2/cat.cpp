//
// Created by shawm on 30-05-2022.
//
#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char *argv[]){

    if(argc == 1)
        while(true){
            string str;
            getline(cin,str);
            cout<<str<<endl;
        }

    for(int i =1; i<argc ;i++) {

        string a;
        ifstream infile;
        
        infile.open(argv[1]);
        getline(infile,a);
        cout<<a<<endl;

    }

}