#include<iostream>
using namespace std;
class node
{   public:
    int data;
    node*left;
    node*right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
    node()
    {
        left=NULL;
        right=NULL;
    }
    void preorder(node*ptr)
    {
        if(ptr==NULL)
        {
            return;
        }
        cout<<ptr->data;
        preorder(ptr->left);
        preorder(ptr->right);
    }
    void inorder(node*ptr)
    {
        if(ptr==NULL)
        {
            return;
        }
        inorder(ptr->left);
        cout<<ptr->data;
        inorder(ptr->right);
    }
    void postorder(node* ptr)
    {
        if(ptr==NULL)
        {
            return;
        }
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data;

    }
};
int main()
{
    node obj;
    node* ptr=new node(1);
    ptr->left=new node(2);
    ptr->right=new node(3);
    ptr->left->left=new node(4);
    ptr->left->right=new node(5);
    ptr->right->left=new node(6);
    ptr->right->right=new node(7);
    cout<<"Preorder representation is :"<<endl;
    obj.preorder(ptr);
    cout<<endl;
    cout<<"Inorder representation is :"<<endl;
    obj.inorder(ptr);
    cout<<endl;
    cout<<"Postorder reprentation is :"<<endl;
    obj.postorder(ptr);
    return 0;

}
