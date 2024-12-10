#include<iostream>
using namespace std;
void hanoi(int,char,char,char);
int main()
{   
    cout<<"Enter the number of rings to be moved to the destination pole :::"<<endl;
    int n;
    cin>>n;
    hanoi(n,'A','C','B');
    return 0;
}
void hanoi(int n,char src,char dest,char med)
{
        if(n==0)
        {   
            return;
        }
        hanoi(n-1,src,med,dest);
        cout<<"Move from "<<src<<" to "<<dest<<endl;
        hanoi(n-1,med,dest,src);
}