#include <stdio.h>
#include <stdlib.h>
struct tree
{
	int data;
	struct tree *left,*right;
};
typedef struct tree *TREE;
TREE root=NULL;
void attach_node(TREE node, TREE prev, TREE cur);
void create()
{
	TREE node,prev,cur;
	node=(TREE)malloc(sizeof(struct tree));
	if(node==NULL)
	{
		printf("\nNOT ENOUGH SPACE!!!");
	}
	else
	{
		printf("\nEnter the data:");
		scanf("%d",&node->data);
		node->left=NULL;
		node->right=NULL;
		attach_node(node,prev,cur);
	}
}

void attach_node(TREE node,TREE prev,TREE cur)
{
	if(root==NULL)
	{
		root=node;
	}
	else
	{
		prev=NULL;
		cur=root;
		while(cur!=NULL)
		{
			prev=cur;
			if(node->data < cur->data)
			{
				cur=cur->left;
			}
			else
			{
				cur=cur->right;
			}
		}
		if(node->data < prev->data)
		{
			prev->left=node;
		}
		else
		{
			prev->right=node;
		}
	}
}
//void display()
//{
//	TREE temp;
//	temp=root;
//	if(temp==NULL) 
//	{
//		printf("\nBinary search tree is empty");
//	}
//	else
//	{
//		while(temp!=NULL)
//		{
//			printf("\n%d",temp->data);
//		}
//		free(temp);
//	}
//}

void preorder_traversal(TREE root)
{
	if(root==NULL)
		return;
	else
	{
		printf("\nThe preorder traversal is: %d\n",root->data);
		preorder_traversal(root->left);
		preorder_traversal(root->right);
	}
}

void inorder_traversal(TREE root)
{
	if(root==NULL)
		return;
	else
	{	
		inorder_traversal(root->left);
		printf("\n%d",root->data);
		inorder_traversal(root->right);
	}
}

void postorder_traversal(TREE root)
{
	
	if(root==NULL)
		return;
	else
	{
		postorder_traversal(root->left);
		postorder_traversal(root->right);
		printf("\n%d",root->data);
	}
}

void search_bst()
{

	TREE temp;
	temp=root;
	int key,found=0;
	printf("\nEnter the key or number to search:");
	scanf("%d",&key);
	if(root==NULL)
	{
		printf("\nThe list is empty!!!");
		return;
	}
	else
	{
		while(temp!= NULL)
		{
			if(key<temp->data)
			{
				temp=temp->left;
			}
			else if (key > temp->data)
			{
				temp=temp->right;
			}
			else
			{ 
				found=1;
				printf("\n%d is present!!!", key);
				return;
			}
		}
	printf("Not found");
	}
}




int main()
{
	int choice;
		while(1)
		{
			
			
			printf("\nBINARY TREE OPERATIONS\n------------------------------\n");
       			printf("\n1.Create Binary search tree\n2.preorder traversal\n3.inorder traversal\n4.postorder traversal\n5.Search BST \n6.Diplay BST\n7.Exit\n");
       			printf("\nEnter your choice:");
       			scanf("\n%d",&choice); 
			switch(choice)
			{
				case 1: create();
					break;
				case 2: preorder_traversal(root);
					break;
				case 3: inorder_traversal(root);
					break;
				case 4: postorder_traversal(root);
					break;
				case 5: search_bst();
					break;
				case 6: //display();
					break;
				case 7: return(0);
				default: printf("\nInvalid choice!!!");
			}
		}
return(0);
}
