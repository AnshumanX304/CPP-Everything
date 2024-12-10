#include<iostream>
using namespace std;
void dup(string,int,int,int);
int main()
{
        string s;
        cout<<"Enter the string :::"<<endl;
        cin>>s;
        int n=s.length();
        dup(s,0,0,n);
        return 0; 

}
void dup(string s,int i,int j,int n)
{    
        if(i==n)
                return;
        while(s[i]==s[j])
                j++;
        cout<<s[i];
        i=j;
        dup(s,i,j,n);
}