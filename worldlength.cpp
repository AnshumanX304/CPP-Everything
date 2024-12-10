#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the world length(including spaces) for the sentence::::"<<endl;
    int n;
    cin>>n;
    cin.ignore();
    char arr[n];
    cin.getline(arr,n+1);
    cin.ignore();
     int i=0;
     int currlength=0,maxlength=0;
     while(1)
    {
            if(arr[i]=='\0')
                break;
            if(arr[i]==' ' || arr[i]=='\0')
            {
                    if(currlength>maxlength)
                        maxlength=currlength;
                    currlength=0;
            }
            else    
                currlength++;
            
            i++;

            
    }
    cout<<"length of the longest world is :::::"<<endl;
    cout<<maxlength<<endl;
    return 0;


}