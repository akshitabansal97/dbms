#include<iostream>
using namespace std;
struct node{
    int key;
    node *left,*right;
};
void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->key<<endl;
        inorder(root->right);
    }
}
struct node * newnode(int item)
{
 node *temp=new node;
 temp->key=item;
 temp->left=NULL;
 temp->right=NULL;
 return temp;
}
struct node *minvalue(node *temp)
{
  node *current=temp;
  current=current->left;
  return current;
}
struct node * insert(struct node *temp,int key)
{
 if(temp==NULL)
    return newnode(key);
 if(key<temp->key)
    temp->left=insert(temp->left,key);
 else
    temp->right=insert(temp->right,key);
 return temp;
}
struct node * del(node *root,int key)
{
 if(root==NULL)
    return root;
 if(key<root->key)
    root->left=del(root->left,key);
 else if(key>root->key)
    root->right=del(root->right,key);
 else
 {
     if(root->left==NULL)
     {
         node *temp=root->right;
         free(root);
         return temp;
     }
     else if(root->right==NULL)
     {
         node *temp=root->left;
         free(root);
         return temp;
     }
     else
     {
         node *temp=minvalue(root->right);
         root->key=temp->key;
         root->right=del(root->right,temp->key);
     }
 }
      return root;
}
int main()
{
    struct node * root=NULL;
    root=insert(root,50);
    root=insert(root,30);
    root=insert(root,20);
    root=insert(root,40);
    root=insert(root,70);
    root=insert(root,60);
    root=insert(root,80);
    cout<<"inorder traversal"<<endl;
    inorder(root);
    cout<<"del 20"<<endl;
    root=del(root,20);
    inorder(root);
    cout<<"del 30"<<endl;
    root=del(root,30);
    inorder(root);
    cout<<"del 50"<<endl;
    root=del(root,50);
    inorder(root);
}
