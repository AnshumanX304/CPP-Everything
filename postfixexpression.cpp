/*IN POSTFIX AND PREFIX EVALUATUION THE ONLY DIFFERENCE IS IN THE WAY OF RUNNING OF THE FOR LOOP
AND THE ORDER OF ALLOCATION OF THE OPERATOR 1 AND OPERATOR 2*/
#include<iostream>
#include<math.h>
#include<stack>
using namespace std;
int postfix(string s)
{
    stack<int> str;
    char ch;
    for(int i=0;i<s.length();i++)
    {   ch=s[i];
        if(ch>='0' && ch<='9')
        {
            str.push(ch-'0');
        }
        else
        {
            int op2=str.top();          //ALERT::::IN PREFIX OPERATOR 1 WAS POPPED FIRST BUT HERE IT IS OPPOSITE....
            str.pop();
            int op1=str.top();
            str.pop();
            switch(s[i])
            {
                case '+':
                    str.push(op1+op2);
                    break;
                case '-':
                    str.push(op1-op2);
                    break;
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
    return str.top();
}
int main()
{
    cout<<postfix("46+2/5*7+");
    return 0;
}