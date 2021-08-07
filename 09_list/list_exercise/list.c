
/*
* Linked list
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/*
* List node
*/
typedef struct linked_list_node
{
	struct linked_list_node* p_next;
	int data;		
} linked_list_node,*p_linked_list_node;

typedef struct linked_list 
{
	linked_list_node* p_head;
	linked_list_node* p_tail;
	linked_list_node* p_cur;	
} linked_list,*p_linked_list;


/*
* linked list create
*/
linked_list*
linked_list_create()
{
	linked_list* p_linked_list;

	p_linked_list = (linked_list*)malloc(sizeof(linked_list));
	if (p_linked_list != NULL)
	{
		p_linked_list->p_cur = NULL;
		p_linked_list->p_head = NULL;
		p_linked_list->p_tail = NULL;
	}
	else
		printf("List memory allocate error!\n");
	return p_linked_list;
}


/*
* Insert node in front of list head
*/
bool
 linked_list_insert_head(linked_list* p_linked_list,int data)
 {
 	linked_list_node* p_node;

 	if (p_linked_list == NULL )
 	{
 		return false;
 	}

 	p_node = (linked_list_node*)malloc(sizeof(linked_list_node));
 	if (p_node == NULL){
 		printf("List node memory allocate error!\n");
 		return false;
 	}
 	p_node->data = data;
 	p_node->p_next = p_linked_list->p_head;
 	p_linked_list->p_head = p_node;

 	if (p_linked_list->p_tail == NULL){
 		p_linked_list->p_tail = p_node;
 	}

 	return true;

 }


// Insert node after the end node
bool
linked_list_insert_tail(linked_list* p_linked_list, int data)
{
    linked_list_node* p_node;

    if (p_linked_list == NULL ) {
        return false;
    }

    p_node = (linked_list_node*)malloc(sizeof(linked_list_node));
    if (p_node == NULL) {
        return false;
    }
    p_node->data = data;
    p_node->p_next = NULL;

    if (p_linked_list->p_tail == NULL) {
        p_linked_list->p_tail = p_node;
        p_linked_list->p_head = p_node;
    }
    else {
        p_linked_list->p_tail->p_next = p_node;
        p_linked_list->p_tail = p_node;
    }


    return true;
}



 /*
* Print list 
 */
 void print_list(linked_list* linked_list)
 {
 	
 	for (linked_list->p_cur = linked_list->p_head; linked_list->p_cur != NULL; linked_list->p_cur =linked_list->p_cur->p_next)
 	{
 		printf("%d\n",(int)linked_list->p_cur->data);
 	}
 }


/*
*Traverse list
*/
 void traverse_list(linked_list* p_linked_list)
 {
 	linked_list_node* p_node ;
 	if ( p_linked_list == NULL )
 	{
 		exit(1);
 	}
 	p_node = p_linked_list->p_head;

 	while(p_node != NULL ){
 		printf("%d\n",p_node->data);
 		p_node = p_node->p_next;
 	}


 }



int main()
{
	linked_list* list = linked_list_create();
	printf("Insert head:%d\n",(linked_list_insert_head(list,100)) );
	printf("Insert tail:%d\n", (linked_list_insert_tail(list,10)));

    printf("Insert tail:%d\n", (linked_list_insert_tail(list,20)));
    printf("Insert tail:%d\n", (linked_list_insert_head(list,200)));
	
	// print_list(list);
	traverse_list(list);

	return 0;
}