/* THIS PROGRAM IS BASED ON FLOYD'S ALGORITHM ALSO KNOWN AS THE HARE AND THE TORTOISE ALGORITHM 
ITS  BASICALLY A PROGRAM TO CHECK IF THE CIRCULAR LIST IS PRESENT IN THE GIVEN SET OF LINKED LIST OR NOT
AND IF THE CIRCULAR LIST IS PRESENT, THEN HOW TO DETECT IT AND REMOVE THE CIRCULAR LIST (OR SIMPLY CONVERT IT TO A
LINEAR LINKED LIST)
THE BASIC CONCEPT AND EXPLANATION FOR THE ALGORITHM IS GIVEN IN THE NOTEBOOK*/
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
    void insert(list* &head,int a)               //for inserting node in the linked list
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
    void display(list *&head)                    //for displaying node entries of a linked list
    {
        list *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->a<<endl;;
            temp=temp->next;
        }
    }

    void circular(list *head,int pos)            //for creating the circular loop from given position
    {
        list *temp=head;
        int count=1;
        list *link;
        while(temp->next!=NULL) 
        {
            if(count==pos)
            {
                link=temp;
            }
            temp=temp->next;
            count++;
        }
        temp->next=link;
    }
    bool detectcircular(list* &head)            //to detect if the loop is circular or not
    {
        list* slow=head;
        list* fast=head;                          //here slow and fast pointer corresponds to the tortoise and hare  
        while(fast!=NULL && fast->next!=NULL)       //pointer explained in the notebok
        {   
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                return 1;
            }
        }
        return 0;
    }
    void removecycle(list* &head)               //to delete the circular loop
    {
        list *fast=head;
        list *slow=head;
        
        do
        {
            slow=slow->next;
            fast=fast->next->next;              

        }while(slow!=fast);
        slow=head;                              
        while(slow->next!=fast->next)           
        {
            slow=slow->next;
            fast=fast->next;
        }  
        fast->next=NULL;
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

   cout<<"Enter the position in the list where the circular list is to be started::::"<<endl;
   int pos;
   cin>>pos;                            //or getting the point where the loop is to be made circular
   obj.circular(head,pos); 

    if(obj.detectcircular(head))        //to detect if the loop is circular or not
        cout<<"Cycle is present !"<<endl;
    else
        cout<<"Cycle not present !"<<endl;
    
    obj.removecycle(head);              //remove the circular loop
    cout<<"List after removing the cycle is ::::"<<endl;
    obj.display(head);                  //displaying the list after removing circular loop

    return 0;
}