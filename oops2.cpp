#include<iostream>
using namespace std;
class a
{
    int a;
    public:
    void display()
    {
        cout<<"display of the base class ::"<<endl;

    }
};
class b:public a
{
    int b;
    public:
    void display()
    {
        cout<<"Display of the derived class :::"<<endl;
    }
};
int main()
{
    a *ptr;
    b obj;
    ptr=&obj;
    ptr->display();
    return 0;
}