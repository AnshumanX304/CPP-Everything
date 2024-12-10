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
void remove(list *head,int n)               //for removing node(other than first node) in the linked list
{   
    list *temp=head;
    while(temp->next->a!=n)
    {
        temp=temp->next;
    }
    list *todelete=temp->next;
    temp->next=(temp->next)->next;
    delete todelete;
};
list* deletehead(list *head)                  //for deleting first node in the linked list
{
    list *temp=head;
    head=temp->next;
    return head;
}
void display(list *head)                    //for displaying node entries of a linked list
{
    list *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->a<<endl;
        temp=temp->next;
    }
} 


};
int main()
{
    cout<<"Enter the number of entries to be made :::"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the values :::"<<endl;
    list obj;
    list *head=NULL;
    int c;
    for(int i=0;i<n;i++)                //loops for entering n nodes in the linked list
    {
        cin>>c;
        obj.insert(head,c);
    }
    cout<<"Entered entries are::::"<<endl;
    obj.display(head);
    cout<<"Enter the element to be deleted :::"<<endl;
    int x;
    cin>>x;
    if(head->a==x)                      //condition for deleting first element
    {
        head=obj.deletehead(head);
        cout<<endl;
        cout<<"Deleted list is ::::"<<endl;
        obj.display(head);              //displaying linked list with first element being deleted
    }
    else                                //condition for removing node other than first node in the linked list
    {
        obj.remove(head,x);
        cout<<endl;
        cout<<"Deleted list is :::"<<endl;
        obj.display(head);                 //displaying linked list with deleted element
    }



    return 0;
}