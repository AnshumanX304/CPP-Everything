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

// list* reverselist(list *&head)              //function to reverse the linked list(using iterativee method)
// {
//     list* previous=NULL;
//     list* current=head;
//     list* nex;
//     while(current!=NULL)
//     {
//         nex=current->next;
//         current->next=previous;

//         previous=current;
//         current=nex;
//     }
//     return previous;
// } 

// list* reverserec(list* head)                //function to reverse the linked list using recursive method
// {   
//     if(head==NULL || head->next==NULL)
//         return head;
//     list *newhead=reverserec(head->next);
//     head->next->next=head;
//     head->next=NULL;
//     return newhead;
    
// }
// list *knode(list *head,int k)           //function to reverse k nodes recursively
// {
//     list *previous=NULL;         //from here
//     list* current=head;
//     list *nex;
//     int count=0;
//     while(current!=NULL && count<k)
//     {
//         nex=current->next;
//         current->next=previous;                                    //within this space k nodes are being reversed

//         previous=current;
//         current=nex;
//         count++;
//     }                           //till here-------same concept used as the one used to reverse the entire linked list
//     if(nex!=NULL)
//     {
//         head->next=knode(nex,k);        //calling knode function recursively to reverse next k nodes
//     }
//     return previous;                    //returning newhead
// }
// int length(list *head)
// {
//     list *temp=head;
//     int count=0;
//     while(temp!=NULL)
//     {
//         temp=temp->next;
//         count++;
//     }
//     return count;
// }
// void appendk(list *&head,int k)
// {
//     int count=length(head);
//     list *newhead;
//     list *tail=head;
//     list *newtail;
//     int i=1;
//     while(tail->next!=NULL)
//     {
//         if(i==count-k)
//             newtail=tail;
        
//         if(i==count-k+1)
//             newhead=tail;

//         tail=tail->next;
//         i++;
//     }
//     newtail->next=NULL;
//     tail->next=head;
//     head=newhead;
// }
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

    // cout<<"The reversed linked list(using iterative method) is ::::"<<endl;     
    // head=obj.reverselist(head);                //calling function to reverse the linked list using iterative method
    // obj.display(head);
    

    // cout<<"The reversed linked list(using recursive method) is ::::"<<endl;
    // head=obj.reverserec(head);              //calling function to reverse the linked list using recursive method
    // obj.display(head);

    // cout<<"Enter the value of k :::"<<endl;         //entering value of k for reversing k number of nodes
    // int k;
    // cin>>k;
    // cout<<"Linked list after reversing "<<k<<" nodes is :::::"<<endl;
    // head=obj.knode(head,k);                         //knode function called for reversing k nodes
    // obj.display(head);                              //displaying k nodes reversed list



    // cout<<"Enter the value of k for last k nodes to be appended ::::"<<endl;
    // cin>>k;
    // obj.appendk(head,k);
    // cout<<"List after being appended is :::::"<<endl;
    // obj.display(head);


    return 0;
}