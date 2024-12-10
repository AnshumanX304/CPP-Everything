#include<iostream>
using namespace std;
int main()
{
        cout<<"Enter the number to be checked if its even or odd ::::"<<endl;
        int n;
        cin>>n;
        if(n&1)
            cout<<"Given number is an odd number "<<endl;
        else    
            cout<<"It is an even number "<<endl;
        return 0;
}

