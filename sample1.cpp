#include<iostream>
using namespace std;
int main()
{
    int t;
    for(int i=0;i<t;i++)
    {
        int n,m,k,x;
        cin>>n>>m>>k>>x;
        int yearinitial=x/n;
        int additionaldays=yearinitial/k;
        int finaldays=x-(additionaldays*m);
        cout<<finaldays;

    }
    return 0;
}