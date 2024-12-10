#include<iostream>
using namespace std;
class list
{   public:
    int a;
    list* next;
    list(int val)
    {
        a=val;
        next=NULL;
    }
    list()
    {
        next=NULL;
    }
    void inserthead(list *&head,int val)
    {
        list *n=new list(val);
        n->next=n;
        head=n;
    }
    void insert(list *&head,int val)
    {
        if(head==NULL)
        {
            inserthead(head,val);
            return ;
        }
        list *n=new list(val);
        list *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->next=head;


    }
    void display(list *head)
    {
        list *temp=head;
        if(head==NULL)
        {
            cout<<"No values entered yet :::"<<endl;
        }
        do
        {
            cout<<temp->a<<" ";
            temp=temp->next;
        }while(temp!=head);
    }
    int length(list *head)
    {
        int count=0;
        list *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
            count++;
        }
        return count;
    }
    void removehead(list *&head)
    {
        list *temp=head;
        do
        {
            temp=temp->next;
        }while(temp->next!=head);
        list *todelete=temp->next;
        head=temp->next->next;
        temp->next=temp->next->next;
        delete todelete;

    }
    void removetail(list *&head)
    {
        list *temp=head;
        do
        {
            temp=temp->next;
        } while (temp->next->next!=head);
        list *todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
        
    }
    void remove(list *&head,int val)
    {
        int count=length(head);
        int i=1;
        list *temp=head;
        do
        {   
            temp=temp->next;
            i++;
        }while(temp->next->a!=val && i<=count);
        if(i==count-1)
        {
            removetail(head);
            return;
        }
        temp->next=temp->next->next;
    }
};
int main()
{
    cout<<"Enter the number of elements in the circular linked list::::"<<endl;
    int n;
    cin>>n;
    list obj;
    list *head=NULL;
    int x;
    cout<<"Enter the elements in the linked list  ::::"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        obj.insert(head,x);
    }
    cout<<"The entered linked list is :::::"<<endl;
    obj.display(head);
    cout<<endl;
    cout<<"Enter the element to be deleted ::::"<<endl;
    int u;
    cin>>u;
    if(head->a==u)
    {
        obj.removehead(head);
        cout<<"linked list  after deletion is :::"<<endl;
        obj.display(head);
    }
    else
    {
        obj.remove(head,u);
        cout<<"linked list after deletion is :::"<<endl;
        obj.display(head);
    }
    return 0;


}

