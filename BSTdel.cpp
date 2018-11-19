#include<iostream>
using namespace std;

struct node{
	int data;
	node* left ;
	node* right;
};

node Insert(node *root,int data)
{
	if(root==NULL){
		root=new node();
		root->data=data;
		root->left = root->right = NULL;
	}
	else if(data<root->data){
		root->left = Insert(root->left,data);
	}
	else{
	root->right = Insert(root->right,data);
	}
	return root;
}

int Findmin(node* root)
{
	if(root==NULL){
		cout<<"Error tree is empty ";
		return -1;
	}
	
	while(root->left!=NULL)
	{root=root->left;}
	return root->data;
}

node* delete(node *root,int data)
{
	if(root==NULL)
	return root;
	else if(data<root->data){root->left=delete(root->left,data);}
   else(data>root->data){root->right=delete(root->right,data);}
   
   else{
	   // case 1 : no child
	   if(root->left==NULL && root->right==NULL){
		   delete root;
		   root=NULL;
	}
		//case 2 : one child
		else if(root->left==NULL){
			node *temp=root;
			root=root->right;
			delete temp;
			
		}
		else if(root->right=NULL){
			node *temp=root;
			root=root->left;
			delete temp;
	}
	else {
		node *temp = findmin(root->right);
		root->data = temp->data;
		root->right = delete(root->right,temp->data);
	}
}
	return root;
}	 

int main()
{
	node* root = NULL; 	
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	  
	delete(root,20);
}
