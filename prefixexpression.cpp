//PROGRAM TO EVALUATE THE PREFIX EXPRESSION AND DISPLAY THE OUTPUT

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
void prefix(string s)
{   char ch;
    stack<int> str;
    for(int i=s.length()-1;i>=0;i--)
    {   ch=s[i];
        if(ch>='0' && ch<='9')              //to find if the string element is number or operator;
        {
            str.push(ch-'0');               //since the elements are entered in string so they are of character type 
        }                                   //so ch contains the values of same type hence ascii value of these elements
                                            //are being send so as they can be operated upon as numbers and not characters
        
        
        else                                //if the element is an operator than this condition follows
        {
            int op1=str.top();              //operand 1 stored
            str.pop();                      //operand 1 popped out of stack
            int op2=str.top();              //operand 2 stored 
            str.pop();                      //operand 2 popped out of stack
            switch(s[i])
            {
                case '+':
                    str.push(op1+op2);
                    break;
                case '-':
                    str.push(op1-op2);       //in this switch case block operations as per the operator encountered is
                    break;                     //being performed and pushed
                case '/':
                    str.push(op1/op2);
                    break;
                case '*':
                    str.push(op1*op2);
                    break;
                case '^':
                    str.push(pow(op1,op2));
                    break;

            }
        }
    }
    cout<<"The result of following expression is :::::"<<endl;
    cout<<str.top();                            //the final result is displayed
}
int main()
{
    cout<<"Enter the prefix expression ::::"<<endl;
    string s;
    cin>>s;
    prefix(s);
    return 0;
}