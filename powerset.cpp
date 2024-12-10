#include<iostream>
using namespace std;
void powerset(string,int,string);
int main()
{
        string str;
        cout<<"Enter the string whose powerset is to be printed :::"<<endl;
        cin>>str;
        powerset(str,0,"");
        return 0;

}
void powerset(string str,int i,string curr)
{   
    int n=str.length();
    if(i==n)
    {
          cout<<curr<<endl;
          return;
    }
    powerset(str,i+1,curr+str[i]);
    powerset(str,i+1,curr);
}