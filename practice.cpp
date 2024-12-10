#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    sort(v.begin(),v.end());
    for(int i=0;i<4;i++)
    {
        cout<<v[i]<<endl;

    }
    return 0;

}