#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node Node;

Node* insertNode(Node *root, int value)
{
	Node *selector = root;
	int finished = 0;
	if(root != NULL)
	{
		while(finished == 0)
		{
			if(value > selector->data)
			{
				if(selector->right != NULL)
				{
					selector = selector->right;
				}
				else
				{
					Node *new_node = malloc(sizeof(Node));
					new_node->data = value;
					new_node->left = NULL;
					new_node->right = NULL;
					selector->right = new_node;
					finished = 1;
				}
			}
			else
			{
				if(selector->left != NULL)
				{
					selector = selector->left;
				}
				else
				{
					Node *new_node = malloc(sizeof(Node));
					new_node->data = value;
					new_node->left = NULL;
					new_node->right = NULL;
					selector->left = new_node;
					finished = 1;
				}
			}
		}
		selector->data = value;
	}
	else
	{
		root = malloc(sizeof(Node));
		root->data = value;
		root->left = NULL;
		root->right = NULL;
	}
	
	return root;
}

void freeSubtree(Node *N){
	if(N != NULL)
	{
		if(N->left != NULL)
		{
			freeSubtree(N->left);
		}
		if(N->right != NULL)
		{
			freeSubtree(N->right);
		}
		free(N);
	}
}

void printSubtree(Node *N)
{
	if(N->left != NULL)
	{
		printf("left != NULL: %d\n", N->data);
		printSubtree(N->left);
	}
	printf("%d\n", N->data);
	if(N->right != NULL)
	{
		printf("right != NULL: %d\n", N->data);
		printSubtree(N->right);
	}
}

int countNodes(Node *N)
{
	int count=0;

	/*
	describe 

	*/

	return count;
}	

Node* deleteNode(Node* root, int value)
{

	/*
	describe 

	*/
	
  	return root; // parent node can update reference
}

int main()
{
	Node *root=NULL;
	
	
    root=insertNode(root, 14);
	root=insertNode(root, 12);
	root=insertNode(root, 6);
	root=insertNode(root, 17);
	root=insertNode(root, 8);
   	printSubtree(root);
	printf("\n");
	root=deleteNode(root,14);
	root=deleteNode(root,8);
   	printSubtree(root);
	freeSubtree(root);
	printf("Number of nodes=%d\n", countNodes(root));
	return 0;

	return 0;
}




