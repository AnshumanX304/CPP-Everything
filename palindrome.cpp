#include<iostream>
#include<string.h>
using namespace std;
int main()
{
        cout<<"enter the size of the word :::"<<endl;
        int n;
        cin>>n;
        char ch[n+1];
        cout<<"enter the word::"<<endl;
        cin>>ch;
        bool flag=0;
        for(int i=0;i<n/2;i++)
        {
                if(ch[i]!=ch[n-i-1])
                {
                        if(ch[i]+32!=ch[n-i-1])
                        {
                                cout<<"Given number is not palindrome"<<endl;
                                flag=1;
                        }
                }
        }
        if(flag==0)
                cout<<"Given number is a palindrome"<<endl;
        return 0;

        


        
}