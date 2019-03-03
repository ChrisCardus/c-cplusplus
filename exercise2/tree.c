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
					Node *new_node;
					if((new_node = malloc(sizeof(Node))) == NULL)
						printf("Memory cannot be allocated.\n");
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
					Node *new_node;
					if((new_node = malloc(sizeof(Node))) == NULL)
						printf("Memory cannot be allocated.\n");
					new_node->data = value;
					new_node->left = NULL;
					new_node->right = NULL;
					selector->left = new_node;
					finished = 1;
				}
			}
		}
	}
	else
	{
		if((root = malloc(sizeof(Node))) == NULL)
			printf("Memory cannot be allocated.\n");
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
			N->left = NULL;
		}
		if(N->right != NULL)
		{
			freeSubtree(N->right);
			N->right = NULL;
		}
		free(N);
	}
}

void printSubtree(Node *N)
{
	if(N->left != NULL)
	{
		printSubtree(N->left);
	}
	printf("%d\n", N->data);
	if(N->right != NULL)
	{
		printSubtree(N->right);
	}
}

int countNodes(Node *N)
{
	int count=0;

	if(N)
	{
		if(N->left != NULL)
		{
			count += countNodes(N->left);
		}
		count++;
		if(N->right != NULL)
		{
			count += countNodes(N->right);
		}
	}

	return count;
}	

void insertTree(Node* root, Node* values)
{
	if(values != NULL)
	{
		if(values->left != NULL)
		{
			insertTree(root, values->left);
		}
		if(values->right != NULL)
		{
			insertTree(root, values->right);
		}
		insertNode(root, values->data);
		free(values);
	}
}

Node* deleteNode(Node* root, int value)
{
	if(root == NULL)								//Checks that the tree actually contains data.
	{
		printf("Cannot delete the node as the tree is empty.\n");
		return root;
	}
	int finished = 0;									//Allows us to loop for an unspecified number of times.
	int lr = 0;											//Check if selector is left or right branch from parent.
	Node *selector = root;								//Keeps track of which node is in focus.
	Node *parent = root;								//Keeps track of the node that was previously the focus.
	while(finished == 0)								//Allows us to loop for an unspecified number of times.
	{
		if(selector == NULL)							//Makes sure that the current focus node isn't empty.
		{
			printf("Node %d does not exist within the tree.\n", value);
			return root;
		}
		if (value == selector->data) {					//Checks if we have reached the node we are looking to delete.
			int left = countNodes(selector->left);		//Counts the number of nodes in the left subtree from the node we are deleting.
			int right = countNodes(selector->right);	//Counts the number of nodes in the right subtree from the node we are deleting.
			if(left == 0 && right == 0)					//Checks if both left and right subtrees are empty.
			{
				if (lr < 0)								//Checks if the node in focus is part of the left or the right branch of the parent.
				{
					free(parent->left);
					parent->left = NULL;				//Replaces the pointer to the deleted node with NULL.
				}
				else if (lr > 0)
				{
					free(parent->right);
					parent->right = NULL;				//Replaces the pointer to the deleted node with NULL.
				}
			}
			else if(right == 0)							//Checks if the right subtree is empty.
			{
				if(lr < 0)
				{
					free(parent->left);
					parent->left = selector->left;		//Replaces the pointer to the deleted node with the left subtree.
				}
				else if(lr > 0)
				{
					free(parent->right);
					parent->right = selector->left;		//Replaces the pointer to the deleted node with the left subtree.
				}
			}
			else if (left == 0)							//Checks if the left subtree is empty.
			{
				if(lr < 0)
				{
					free(parent->left);
					parent->left = selector->right;		//Replaces the pointer to the deleted node with the right subtree.
				}
				else if(lr > 0)
				{
					free(parent->right);
					parent->right = selector->right;	//Replaces the pointer to the deleted node with the right subtree.
				}
			}
			else if (left >= right)						//Checks if the left subtree is the same size as or larger than the right subtree.
			{
				Node *right = selector->right;			//Create a pointer to the right subtree of the deleted node.
				selector = selector->left;				//Moves the selector one step down the left subtree.
				Node *temp = selector->right;			//Create a pointer to the right subtree of the node to be moved.
				selector->right = right;				//Change the right subtree pointer to the right subtree of the deleted node.
				insertTree(right, temp);				//Reinsert the nodes from the temp subtree to the new subtree.
				if(lr < 0)								//Checks if the replacement node should come from the left or right branch of the parent.
				{
					free(parent->left);
					parent->left = selector;			//Replaces the pointer to the deleted node with a pointer to the replacement node.
				}
				else if (lr > 0)
				{
					free(parent->right);
					parent->right = selector;			//Replaces the pointer to the deleted node with a pointer to the replacement node.
				}
				else
				{
					free(parent);
					root = selector;
				}
				
			}
			else
			{
				Node *left = selector->left;			//Create a pointer to the left subtree of the deleted node.
				selector = selector->right;				//Moves the selector one step down the right subtree.
				Node *temp = selector->left;			//Create a pointer to the left subtree of the node to be moved.
				selector->left = left;					//Change the left subtree pointer to the left subtree of the deleted node.
				insertTree(left, temp);					//Reinsert the nodes from the temp subtree to the new subtree.
				if(lr < 0)								//Checks if the replacement node should come from the left or right branch of the parent.
				{
					free(parent->left);
					parent->left = selector;			//Replaces the pointer to the deleted node with a pointer to the replacement node.
				}
				else if (lr > 0)
				{
					free(parent->right);
					parent->right = selector;			//Replaces the pointer to the deleted node with a pointer to the replacement node.
				}
				else
				{
					free(parent);
					root = selector;
				}
				
			}
			finished = 1;								//Signals that the loop can now finish.
			
		}
		else if(value <= selector->data)				//Checks if the node value we are searching for is less than or equal to the current node.
		{
			parent = selector;							//Move the parent node one step down the tree.
			lr = -1;									//Record which branch from the parent the selector is moving.
			selector = selector->left;					//Move the selector one step down the left branch of the tree.
		}
		else if (value > selector->data)				//Checks if the node value we are searching for is greater than the current node.
		{
			parent = selector;							//Move the parent node one step down the tree.
			lr = 1;										//Record which branch from the parent the selector is moving.
			selector = selector->right;					//Move the selector one step down the right branch of the tree.
		}
	}
	
  	return root; 										//Return the tree with the specified node now removed.
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
}