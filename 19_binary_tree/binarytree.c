
//Binary Tree

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


//Tree node
typedef struct tree_node {
	/*Left tree pointer*/
	struct tree_node* left;
	/*Right tree pointer*/
	struct tree_node* right;
	/*Key*/
	char key;
} tree_node;

//Create a tree node
tree_node* tree_create_node (char key)
{
	tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
	if ( node == NULL )  return NULL;
	node->key = key;
	node->left = NULL;
	node->right = NULL;

	return node;
}


//Create a binary tree
tree_node* tree_create()
{
	char str;
	tree_node* current;
	scanf("%c",&str);
	if ( '#' == str )
	{
		current = NULL;
	}
	else
	{
		current = tree_create_node(str);
		current->left = tree_create();
		current->right = tree_create();
	}

	return current;
}



	//Tree traverse
	//Pre-order traverse
	void preorder_traverse(tree_node* node)
	{
		if ( node != NULL)
		{
			printf("%c \t",node->key );
			preorder_traverse(node->left);
			preorder_traverse(node->right);

		}

	}


	//In-order traverse
	void inorder_traverse (tree_node* node)
	{
		if (node != NULL)
		{
			inorder_traverse(node->left);
			printf("%c \t",node->key );
			inorder_traverse(node->right);
		}
	}

	//Post-order traverse
	void postorder_traverse(tree_node* node)
	{
		if (node != NULL)
		{
			postorder_traverse(node->left);
			postorder_traverse(node->right);
			printf("%c \t",node->key );
		}
	}

	//Level-traverse
	void level_traverse(tree_node* root)
	{
		//Create a queue
		queue* queue = create_queue();

		if ( root != NULL)	
		{
			enqueue(queue,root);
		}

		while(queue->length)
		{
			tree_node* current = (tree_node*)dequeue(queue);
			printf("%c \t",current->key );
			if (current->left) enqueue(queue,current->left);
			if (current->right) enqueue(queue,current->right);
		}

		//Release the queue after used
		release_queue(queue);
	}
















int main(int argc, char const *argv[])
{
	
	//Test code
	/* ABD##E##CF##G## */
    tree_node *root = tree_create();

    printf("\n前序遍历（递归实现）：");
    preorder_traverse(root);

    printf("\n中序遍历（递归实现）：");
    inorder_traverse(root);

    printf("\n后序遍历（递归实现）：");
    postorder_traverse(root);


    printf("\n\n层次遍历0：");
    level_traverse(root);
    printf("\n");








	return 0;
}