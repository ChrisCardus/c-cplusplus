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
	/*
	describe 

	*/
	return root;
}

void freeSubtree(Node *N){
	/*
	describe 

	*/
}

void printSubtree(Node *N)
{
	/*
	describe 

	*/
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




