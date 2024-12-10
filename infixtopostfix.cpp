#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
int prec(char s)
{
    if(s=='^')
        return 3;
    else if(s=='/' || s=='*')
        return 2;
    else if(s=='+' || s=='-')
        return 1;
    else return -1;
}
string infixtopostfix(string s)
{
    stack<char> st;
    string ans="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
           ans+=s[i]; 
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && prec(st.top())>prec(s[i]))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        ans=ans+st.top();
        st.pop();

    }
    return ans;
}
int main()
{
    cout<<"Enter the infix expression :::::"<<endl;
    string s;
    cin>>s;
    cout<<"Postfixexpression obtained is :::"<<endl;
    cout<<infixtopostfix(s);
    return 0;
}