#include <iostream>
#include <stdbool.h>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

bool isBalanced(int argc, string inputfile)
{
     vector<string> vectorBraces;
     ifstream newfile(inputfile);

     if(newfile.is_open())
     {
         string line;
         while(getline(newfile, line))
         {
             
         }
     }



};

int main(int argc, char* argv[])
{
    string inputfile = argv[1];
    isBalanced(argc, inputfile); 
}