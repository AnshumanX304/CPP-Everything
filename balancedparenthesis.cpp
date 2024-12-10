//PROGRAM EXPLAINED IN THE NOTEBOOK
#include<iostream>
#include<stack>
using namespace std;
int prec(char ch)
{
    if(ch=='^')
        return 3;
    else if(ch=='/'||ch=='*')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    elsereturn -1;
}
bool parenthesis(string s)
{
    stack<char> st;
    bool answer=1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='{' || s[i]=='[' || s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(st.top()=='(')
            {
                st.pop();
            } 
            else    
            {
                answer=false;
                break;  
            }      
        }
        else if(s[i]=='}')
        {
            if(st.top()=='{')
            {
                st.pop();
            } 
            else    
            {
                answer=false;
                break;  
            }   
        }
        else if(s[i]==']')
        {
            if(st.top()=='[')
            {
                st.pop();
            } 
            else    
            {
                answer=false;
                break;  
            }     
        }
        else
        {
            cout<<"fuck off !!!!"<<endl;
            break;
        }
        
    }
    if(!st.empty())
        return false;

    return answer;
}
int main()
{
    cout<<"Enter the parenthesis combination ::::"<<endl;
    string s;
    cin>>s;
    cout<<parenthesis(s);
    return 0;
}