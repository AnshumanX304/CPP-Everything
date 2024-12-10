#include<iostream>
using namespace std;

class list                                                                                                                                                                                   
{   public:
    int a;
    list *next;
    list *previous;
    list(int val)
    {
        a=val;
        next=NULL;
        previous=NULL;
    }
    
    list()
    {
        next=NULL;
        previous=NULL;
    }
    void enter(list* &head,int val)
    {
        if(head==NULL)
        {
            inserthead(head,val);
            return;
        }
        list *n=new list(val);
        list *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
        n->previous=temp;
    }
    void inserthead(list* &head,int val)
    {
        list *n=new list(val);
        n->next=head;
        if(head!=NULL)
        {
            head->previous=n;
        }
        head=n;
    }
    void display(list* head)
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
        list *temp=head;
        while(temp->next->a!=val)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        temp->next->previous=temp;
        
    }
    list* deletehead(list *head)
    {
        list *temp=head;
        head=head->next;
        head->next->previous=NULL;
        return head;
    }
    list *reverse(list *head)
    {
        list *prev=NULL;
        list *current=head;
        list *nex;
        while(current!=NULL)
        {
            nex=current->next;
            current->next=prev;
            current->previous=nex;
            
            prev=current;
            current=nex;
        }
        return prev;
    }
    void prevdisplay(list *head)
    {
        list *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        list *prev=temp->previous;
        while(prev!=NULL)
        {
            cout<<prev->a<<endl;
            prev=prev->previous;
        }
    }
};
int  main()
{
    cout<<"Enter the number of records you want to make"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the values :::"<<endl;
    int x;
    list obj;
    list *head=NULL;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        obj.enter(head,x);

    }
    cout<<"The entered array list is :::"<<endl;
    obj.display(head);
    cout<<"Enter the element to be deleted :::"<<endl;
    cin>>n;
    if(head->a==n)
    {
        head=obj.deletehead(head);
        cout<<"list afer deletion is :::"<<endl;
        obj.display(head);
    }
    else
    {
        obj.remove(head,n);
        cout<<"List after deletion is :::"<<endl;
        obj.display(head);
    }
    cout<<"list after reversal is ::::"<<endl;
    head=obj.reverse(head);
    obj.display(head);

    cout<<"The reversed list by making use of previous pointer is ::::"<<endl;
    obj.prevdisplay(head);
    return 0;
}