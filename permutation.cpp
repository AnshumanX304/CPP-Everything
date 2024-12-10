#include<bits/stdc++.h>

using namespace std;
void permutation(string,string);
int main()
{   
    cout<<"Enter the value in the string :::"<<endl;
    string s;
    cin>>s;
    permutation(s,"");
    return 0;
}
void permutation(string s,string ans)
{   
    if(s.length()==0)
    {   
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++)
    {   
        char ch=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        permutation(ros,ans+ch);
    }

}