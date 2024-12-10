#include<iostream>
using namespace std;
void subset(string,int,string);
int main()
{
    cout<<"Enter the value in string ::::"<<endl;
    string s;
    cin>>s;
    subset(s,0,"");
    return 0;

}
void subset(string s,int i,string cur)
{   int n=s.length();
    if(i==n)
    {
            cout<<cur<<endl;
            return;
    }
     
    subset(s,i+1,cur+s[i]);
    subset(s,i+1,cur);
}

