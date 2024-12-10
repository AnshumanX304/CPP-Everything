#include<iostream>
#include<queue>
using namespace std;
class node
{   public:
    int val;
    node* left;
    node* right;
    node(int data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
    node()
    {
        val=-1;
        left=NULL;
        right=NULL;
    }

};
node* buildtree(node *root)
{
    cout<<"Enter the data in the node ::"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)
    {
        return NULL;
    }
    cout<<"Enter the data in the left of the "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter the data in the right of the "<<data<<endl;
    root->right=buildtree(root->right);
    return root;
}
void buildlevelorder(node* root)
{
   int data;
   cout<<"Enter the data for root ::"<<endl;
   cin>>data;
   root=new node(data);
   queue<node*> q;
   q.push(root);
   while(!q.empty())
   {
       node* temp=q.front();
       q.pop();
       int leftnode;
       cout<<"Enter the data for left of "<<temp->val<<endl;
       cin>>leftnode;
       if(leftnode!=-1)
       {
            temp->left=new node(leftnode);
            q.push(temp->left);
       }

       int rightnode;
       cout<<"Enter the data for left of "<<temp->val<<endl;
       cin>>rightnode;
       if(rightnode!=-1)
       {
            temp->right=new node(rightnode);
            q.push(temp->right);
       }



   }

}
void levelordertraversal(node* root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        if(temp!=NULL)
        {
            cout<<temp->val<<" ";

            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
        else
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
    }
}
void preordertraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->val<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}

int main()
{
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    node* root=NULL;
    root=buildtree(root);
    cout<<"Binary tree printed in level order traversal is ::"<<endl;
    levelordertraversal(root);
    cout<<"Binary tree printed in preorder traversal is ::"<<endl;
    preordertraversal(root);
    cout<<endl;
    cout<<"Binary tree printed in inorder traversal is :"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Binary tree printed in postorder traversal is :"<<endl;
    postorder(root);


    return 0;
}
