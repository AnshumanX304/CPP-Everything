#include<iostream>
using namespace std;
class list
{   public:
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
    void enter(list *&head,int val)
    {
        list *n=new list(val);
        if(head==NULL)
        {
            head=n;
            return;
        }
        list *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
    void display(list *&head)
    {
        list *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->a<<endl;
            temp=temp->next;
        }
    }
    void remove(list *&head,int val)
    {
        list* temp=head;
        while(temp->next->a!=val)
        {
            temp=temp->next;
        }
        list *todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }
    void removehead(list *&head)
    {
        list *temp=head;
        head=head->next;
        delete temp;
    }
    list *reverse(list *head)
    {
        list *previous=NULL;
        list *current=head;
        list *nex;
        while(current!=NULL)
        {
            nex=current->next;
            current->next=previous;
            previous=current;
            current=nex;
        }
        return previous;
    }
    list *recreverse(list *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        list* newhead=recreverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
    list* node(list *head,int k)
    {
        list* previous=NULL;
        list *current=head;
        list *nex;
        int count=0;
        while(current!=NULL && count<k)
        {
            nex=current->next;
            current->next=previous;
            previous=current;
            current=nex;
            count++;
        }
        if(nex!=NULL)
        {
            head->next=node(nex,k);
        }
        return previous;
    }
};
int main()
{
    cout<<"Enter the number of enteries you want to make ::::"<<endl;
    int n;
    cin>>n;
    list obj;
    list *head=NULL;
    int x;
    cout<<"Enter the elements :::"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        obj.enter(head,x);
    }
    cout<<"list entered is :::"<<endl;
    obj.display(head);
    cout<<"Enter the element to be deleted :::"<<endl;
    int n1;
    cin>>n1;
    if(head->a==n1)
    {
        obj.removehead(head);
        cout<<"The deleted list is :::::"<<endl;
        obj.display(head);
    }
    else
    {
        obj.remove(head,n1);
        cout<<"The deleted list is :::::"<<endl;
        obj.display(head);
    }
    cout<<"The reversed list (using iterative approach) is ::::"<<endl;
    head=obj.reverse(head);
    obj.display(head);
    cout<<endl<<"The reversed list (using recursive approach is)  is :::::"<<endl;
    head=obj.recreverse(head);
    obj.display(head);

    cout<<"Enter the number of nodes to be reversed :::"<<endl;
    int k;
    cin>>k;
    head=obj.node(head,k);
    cout<<"The k nodes reversed list is ::::"<<endl;
    obj.display(head);

    return 0;
}
