#include<iostream>
using namespace std;
class complexno
{
    int real;
    int imag;
    public:
    void enter()
    {
        cin>>real;
        cin>>imag;
    }
    void display()
    {
        cout<<real<<"+i"<<imag;
    }
    complexno operator + (complexno &obj)
    {
        complexno res;
        res.real=real+obj.real;
        res.imag=imag+obj.imag;
        return res;
    }

};
int main()
{
    complexno obj1,obj2;
    cout<<"Enter the elements in the object 1 ::::"<<endl;
    obj1.enter();
    cout<<"enter the elements in the object 2:::"<<endl;
    obj2.enter();
    complexno c=obj1+obj2;
    cout<<"Complex number after the adddition is :::"<<endl;
    c.display();
    return 0;
}
