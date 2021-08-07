#include <stdio.h>
#include <stdlib.h>

// Create linkedlist
typedef struct Linkedlist{
	int data;
	struct Linkedlist *next;
} Linkedlist;

	// Init linklist
    Linkedlist *create (int n)
    {
	Linkedlist *head,*node,*tail;
	head = (Linkedlist*)malloc(sizeof(Linkedlist));
	tail = head;		// Empty linklist

	// Allocate memory for nodes
	for( int i = 0; i < n; i++ )
	{
		node=(Linkedlist*)malloc(sizeof(Linkedlist));
		node->data = 0;
		tail->next = node;
		tail = node;
	}

	tail->next = NULL;
	return head;
   };

int main()
{
    Linkedlist* list = (Linkedlist*)create(10);
    for (int i = 1;list->next != NULL;i++)
    {	
    	list = list->next;
		printf("Node %d = %d\n",i,list->data);
    }

	return 0;
}

