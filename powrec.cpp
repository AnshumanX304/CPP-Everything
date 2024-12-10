#include<iostream>
using namespace std;
int powrec(int,int);
int main()
{
    cout<<"enter the number and the power which is to be calculated :::"<<endl;
    int n;
    int p;
    cin>>n;
    cin>>p;
    cout<<powrec(n,p);
    return 0;

}
int powrec(int n,int p)
{
        if(p==0)
            return 1;
        return n*powrec(n,p-1);


}