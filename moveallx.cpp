#include<iostream>
using namespace std;
string movex(string);
int main()
{
    string s;
    cout<<"enter the string :::"<<endl;
    cin>>s;
    string s1=movex(s);
    cout<<s1;
    return 0;
}
string movex(string s)
{
    if(s.length()==0)
    {   
        return "";
    }
    char ch=s[0];
    string ans=s.substr(1);
    if(ch=='x')
        return ans+ch;
    else    
        return ch+ans;
}