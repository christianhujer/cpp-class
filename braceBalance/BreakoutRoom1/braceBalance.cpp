#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool Pair(char left,char right)
{
    if(left == '(' && right == ')') return true;
    else if(left == '{' && right == '}') return true;
    else if(left == '[' && right == ']') return true;
    return false;
}
bool isBalanced(string strings)
{
    stack<char>  S;
    for(int i =0;i<strings.length();i++)
    {
        if(strings[i] == '(' || strings[i] == '{' || strings[i] == '[')
            S.push(strings[i]);
        else if(strings[i] == ')' || strings[i] == '}' || strings[i] == ']')
        {
            if(S.empty() || !Pair(S.top(),strings[i]))
                return false;
            else
                S.pop();
        }
    }
    return S.empty() ? true:false;
}

int main()
{
    string str;
    cout<<"Enter a brace:  ";
    cin>>str;
    if(isBalanced(str))
        cout<<"Yes, balanced\n"<<str;
    else
        cout<<"Not Balanced\n"<<str;
}