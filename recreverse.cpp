#include<iostream>
using namespace std;
string revstr(string,int);
int main()
{
    cout<<"enter the string to be reversed ::::"<<endl;
    string s;
    cin>>s;
    string s1=revstr(s,0);
    cout<<s1;
    return 0;
}
string revstr(string s,int i)
{
        int n=s.length();
        if(i==n/2)
        {   
            return s;
        }
        char temp=s[i];
        s[i]=s[n-1-i];
        s[n-i-1]=temp;
        return revstr(s,i+1);

        
}