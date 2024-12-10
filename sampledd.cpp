#include<iostream>
using namespace std;
void enter(char *student,int n)
{
    cout<<"Enter the name of the student ::::"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>student[i];
    }
    for(int i=0;i<n;i++)
        cout<<student[i];
}
int main()
{
    cout<<"Enter the number of entries to be made :::"<<endl;
    int n;
    cin>>n;
    char *student=new char[n*24];
    enter(student,n);
    return 0;

}