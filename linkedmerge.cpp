#include<iostream>
using namespace std;
class list
{
    public:
    int a;
    list *next;
    list(int val)
    {
        a=val;
        next=NULL;
    }
    list()
    {
        next=NULL;
    }
void insert(list* &head,int a)                //for inserting node in the linked list
{
    list *n=new list(a);
    if(head==NULL)
    {
        head=n;
        return;
    }
    list* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    temp->next->next=NULL;


}
void display(list *head)                    //for displaying node entries of a linked list
{
    list *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->a<<" ";
        temp=temp->next;
    }
}
list * merge(list *&head1,list *&head2)
{
    list *temp1=head1;
    list *temp2=head2;
    list *temp=new list(-1);
    list *newhead=temp;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->a<temp2->a)
        {
            temp->next=temp1;
            temp=temp->next;
            temp1=temp1->next;
        }
        else
        {
            temp->next=temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL)
    {
        temp->next=temp1;
        temp=temp->next;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        temp->next=temp2;
        temp=temp->next;
        temp2=temp2->next;
    }
    return newhead->next;
}
};    
int main()
{   int x;
    cout<<"enter the size of the sorted list 1::::"<<endl;
    int n1;
    cin>>n1;
    list *head=NULL;
    list obj;
    list *head1=NULL;
    list *head2=NULL;
    cout<<"Enter the elements ::::"<<endl;              //enter the elements in the sorted list 1
    for(int i=0;i<n1;i++)
    {
        cin>>x;                         
        obj.insert(head1,x);
    }
    cout<<"Enter the size of the list 2::::"<<endl;     //enter the elements in the sorted list 2
    int n2;
    cin>>n2;
    cout<<"Enter the elements ::::"<<endl;
    for(int i=0;i<n2;i++)
    {
        cin>>x;
        obj.insert(head2,x);
    }
    cout<<"Entered list are ::::"<<endl;                //displaying the entered list
    obj.display(head1);
    cout<<endl;
    obj.display(head2);
    cout<<endl;
    head=obj.merge(head1,head2);
    cout<<"Sorted list is ::::"<<endl;
    
    obj.display(head);

    return 0;


    
}