#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
struct s
{
    int a;
    string ch;
    void enter()
    {
        cout<<"Enter the number "<<endl;
        cin>>a;
        cout<<"Enter the name :::"<<endl;
        cin>>ch;
    }
    void show()
    {
        cout<<"Entered number is :::"<<endl;
        cout<<a<<endl;
        cout<<"Entered  name is :::"<<endl;
        cout<<ch<<endl;
    }
};
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    auto it=upper_bound(v.begin(),v.end(),1);
    cout<<it-v.begin()<<endl;
    return 0;
}