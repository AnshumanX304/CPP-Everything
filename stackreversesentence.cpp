#include<iostream>
#include<stack>
using namespace std;
void reversesentence(string s)
{
    int l=s.length();
    stack<string> st;
    for(int i=0;i<l;i++)
    {
        string ch="";
        while(s[i]!=' ' && i<l)
        {
            ch=ch+s[i];
            i++;
        }
        st.push(ch);

    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
}
int main()
{
    cout<<"Enter the sentence "<<endl;
    string s;
    getline(cin,s);
    reversesentence(s);
    return 0;
}
