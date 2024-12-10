#include<iostream>
using namespace std;
class list
{   public:
    int a;
    list *next=NULL;
    list(int val)
    {
        a=val;
        next=NULL;
    }
    list()
    {
        next=NULL;
    }
    void insert(list *&head,int val)
    {   list *n=new list(val);
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
    }
    void display(list *&head)
    {
        list *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->a<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    list *oddeven(list* odd,list *even)
    {   list *head=odd;
        list *evenstart=even;                           //saving the pointer denoting the start of the even list
        while(odd->next!=NULL && even->next!=NULL)    //so that it can be merge later with the last element of the odd list      
        {
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;           //in this loop all odd numbered elemets and all even numbered elements are 
            even=even->next;                   //being joined together separately
        }
        odd->next=evenstart;                        //alloting the next of last odd member with the evenstart
        if(odd->next==NULL)
        {
            even->next=NULL;                //see this explanation in notebook
        }
        return head;

    }
};
int main()
{
    cout<<"Enter the number of elements you want to enter :::"<<endl;
    int n;
    cin>>n;
    list obj;
    list *head=NULL;
    cout<<"Enter the elements :::::"<<endl;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        obj.insert(head,x);
    }
    cout<<"Entered list is :::"<<endl;
    obj.display(head);
    list *head1=head;                //odd pointer
    list* head2=head->next;            //even pointer
    head=obj.oddeven(head1,head2);
    cout<<"List after putting odd elements after even elements :::::"<<endl;
    obj.display(head);
    return 0;

}