//PROGRAM TO FIND THE INTERSECTION POINT OF TWO INTERSECTING LINKED LISTS.
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
        cout<<temp->a<<endl;
        temp=temp->next;
    }
}
int length(list *head)                  //length to find the length of the passed list
{
    list *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;                       //returning the length
}
void join(list *&head2,list *&head,int k)       //function to join two lists at given node
{
    list *temp2=head2;
    list *temp1=head;
    int i=0;
    while(temp1->next!=NULL)
    {
        
        i++;
        if(i==k)
        {
            break;
        }
        temp1=temp1->next;
    }//after this loop temp1->next is pointing towards the address of the node
     // which is to be made common between two given lists
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;          //getting to the end of the second list
    } 
    temp2->next=temp1->next;        //filling next of the last node of second list with the
                                    // address of the node to be made common
}
void intersection(list *head1,list *head2)      //function to find the intersection of the two INTERSECTED linked lists
{
    int k1=length(head1);
    int k2=length(head2);  
    int k;
    if(k1>k2)              //APPLYING CONDITIONS TO CHECK IF THE FIRST LIST IS GREATER OR THE SECOND
        k=k1-k2;
    else    
        k=k2-k1;            //K IS USED TO STORE THE SIZE DIFFERENCE OF TWO LISTS
    list *temp1=head1;
    list *temp2=head2;

    int ptr=0;
    if(k1>k2)                  //THIS STATEMENT WILL WORK ONLY IF LIST 1 IS GREATER THAN LIST 2
    {
        while(ptr<k)
        {
            temp1=temp1->next;         //LIST 1 IS TRAVERSED K TIMES SO THAT THE  
            ptr++;                      //CURRENT POINTER OF LIST 1 IS AT EQUAL DISTANCE WITH THE POINTER OF 
        }                                  //SECOND LIST FROM THE INTERSECTION POINT
    }
    else                                       //SIMILAR CONCEPT AS ABOVE WITH JUST THE DIFFERENCE THAT 
    {                                           //HERE LENGTH OF SECOND LIST IS > THE FIRST ONE
        while(ptr<k)
        {
            temp2=temp2->next;
            ptr++;
        }
    }
    while(temp1->next!=temp2->next)             //LOOP TO TRAVERSE BOTH LISTS AT THE SAME TIME SO AS TO 
    {                                           //FIND THEIR INTERSECTION POINTS
        temp1=temp1->next;
        temp2=temp2->next;

    }
    cout<<"The intersection of given two linked lists is ::::"<<endl;
    cout<<temp1->next->a;                           //DISPLAYING THE INTERSECTION POINTS


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
    obj.display(head);                  //displaying original list


    cout<<"Enter the node number where you want to append the new list ::::"<<endl;
    cin>>n;                                    //intersection point
    cout<<"Enter the number of elements in the new list ::::"<<endl;
    int h;                                   //entering the size of list to be appended/intersected in previous list
    cin>>h;
    list *head2=NULL;
    cout<<"Enter the elements ::::"<<endl;          //entering elements in new list
    for(int i=0;i<h;i++)
    {
         cin>>c;
         obj.insert(head2,c);
    }
    obj.join(head2,head,n);                         //both lists send to be joined via a common intersection at node n
    cout<<"The joined lists are ::::"<<endl;
    obj.display(head);                              //individually displaying both the intersected lists
    cout<<endl;
    obj.display(head2);

    obj.intersection(head,head2);                   //parameters sent to find the intersection point
    return 0;
}