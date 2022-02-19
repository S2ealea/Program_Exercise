#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	

// Define list node struct
	typedef struct node 
	{
		struct node * next;
		int data;		
	} list;

// Create single list
list * create_list()
{
	//1.Create a new node
	list * head = (list*)malloc(sizeof(list));
	if( head == NULL )
		return NULL;

	//2.Init node
	head->data = 0;   //Stores the length of the list
	head->next = NULL;

	return head;

}	


// Insert a node into the list
list * list_insert_node ( list* head, int data, int pos )
{
	int i;
	list *curr = head;

	if ( pos > head->data )   // The inserting pos longger than the list
		return NULL;

	//Insertion
	//1.Create a node and init
	list *node = (list*)malloc(sizeof(list));
	if ( node == NULL ) return NULL;

	node->data = data;
	node->next = NULL;

	//2.Traverse the list ,searching for the inserting pos
	for (int i = 0; i < pos; ++i)
	{
		curr = curr->next;
	}

	//3.Insert
	node->next = curr->next;
	curr->next = node;

	//4.Update the list length
	head->data++;

	return head;
}

	
	//Travserion
	//Print out the list data, except the head node
	void traverse( list *head)
	{
		list* curr = head->next;
		while(curr != NULL)
		{
			printf("%d\t",curr->data );
			curr = curr->next;

		}

		printf("\n");

	}


	//Deletion
	list* list_delete_data(list* head, int pos)
	{
		int i = 0;
		list* curr = head;

		// If the node to delete is out of the list, then it is invalided.
		if ( pos > curr->data ) return NULL;


		//1.Traverse the list until to the target node
		for (int i = 0; i < pos; i++)
		{
			curr = curr->next;
		}

		//2.Temp recorde the deleting node
		list* temp = curr->next;

		//3.Delete the node
		curr->next = curr->next->next;

		//4.Free the deleted node memory
		free(temp);
		head->data--;

		return head;
	}





// Test in the main
	list *l = create_list();
	// printf("当前链表长度：%d\n", l->data);
	// list_insert_node(l, 1, 0);
	// printf("当前链表长度：%d\n", l->data);

	//Insert data many times
	for( int i=0;i<5;i++){

		list_insert_node(l, i, 0);
		traverse(l);
    }

    list_delete_data(l, 0);
	traverse(l);


	return 0;
}