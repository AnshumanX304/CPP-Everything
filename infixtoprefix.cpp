/*IN THIS PROGRAM WE WILL DO JUST AS WE DID IN THE PROGRAM FOR INFIX TO POSTFIX
WITH JUST THE DIFFERENCE BEING THAT HERE THE STRING WILL BE REVERSED BEFORE CONTINUING THE OPERATION 
BECAUSE OF THE REVERSAL THE '(' AND ')' BRACKET WILL BE INTERCHANGED SO WE NEED TO FIX THEM EITHER BEFORE PASSING 
THEM ONTO THE FUNCTION OR WHILE OPERATING THEM INSIDE THE FUNCTION
IN THIS PROGRAM WE DID IT WHILE OPERATING ON THE PASSED REVERSED STRING SO HERE POSITION OF  '(' AND ')' ARE 
INTERCHANGED WRT THE PROGRAM MADE FOR CONVERTING FROM INFIX TO POSTFIX*/
#include<iostream>
#include<math.h>
#include<stack>
#include<string>
#include<algorithm>
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
string infixtoprefix(string s)
{
    stack<char> st;
    string ans="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
           ans+=s[i]; 
        }
        else if(s[i]==')')              //HERE ')' MEANS '(' AS THE STRING IS REVERSED SO OPERATION WILL BE DONE            
        {                              // BY CONSIDERING IT '(' HENCE IT IS PUSHED
            st.push(s[i]);
        }
        else if(s[i]=='(')              //HERE '(' MEANS ')' AS THE STRING IS REVERSED SO OPERATION WILL BE DONE 
        {                               // BY CONSIDERING IT ')' HENCE THE STACK IS POPPED OUT UNTIL )(WHICH LOGICALLY MEANS '(') 
            while(!st.empty() && st.top()!=')')//IS ENCOUNTERED
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
            while(!st.empty() && prec(st.top())>=prec(s[i]))
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
    reverse(ans.begin(),ans.end());     //ANSWER IS REVERSED BEFORE SENDING IT TO THE MAIN
    return ans;
}
int main()
{
    cout<<"Enter the infix expression :::::"<<endl;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    cout<<"prefixexpression obtained is :::"<<endl;
    cout<<infixtoprefix(s);
    return 0;
}