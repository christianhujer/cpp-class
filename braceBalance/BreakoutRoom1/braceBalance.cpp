#include <iostream>
#include <stdbool.h>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

bool Pair(char left, char right)
{
    if (left == '(' && right == ')')
        return true;
    else if (left == '{' && right == '}')
        return true;
    else if (left == '[' && right == ']')
        return true;
    return false;
}

bool isBalanced(string inputfile)
{
    stack<char> S;
    ifstream newfile(inputfile);

    if (newfile.is_open())
    {
        string line;
        while (getline(newfile, line))
        {

            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == '(' || line[i] == '{' || line[i] == '[')
                    S.push(line[i]);
                else if (line[i] == ')' || line[i] == '}' || line[i] == ']')
                {
                    if (S.empty() || !Pair(S.top(), line[i]))
                        return false;
                    else
                        S.pop();
                }
            }
        }
    }
    return S.empty() ? true : false;
}

int main(int argc, char *argv[])
{
    string inputfile = argv[1];
    bool exitStatus = EXIT_SUCCESS;
    if (isBalanced(inputfile))
    {
        cout<<"Balanced";
    }
    else{
        cerr<<"error: missing ";
        exitStatus = EXIT_FAILURE;
    }
    return exitStatus;

}