//Doublely linked list

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	//Node
	typedef struct list_node 
	{
		struct list_node* prev;
		struct list_node* next;
		void* value;
	} list_node;


	//Doubly linkded list
	typedef struct dlist
	{
		unsigned long length;
		list_node* head;
		list_node* tail;		
	} dlist;


	//Create the doubly linked list
	dlist* create_list(  )
	{
		dlist* list = (struct dlist*)malloc(sizeof(struct dlist));
		if (list == NULL )  return NULL;

		//Init
		list->head = list->tail = NULL;
		list->length = 0;	

		return list;	
	}






	//Insert a node into the list head
	dlist* list_add_node_head(dlist* list, void* value)
	{

		//Create a node
		list_node* node = (list_node* )malloc(sizeof(list_node));
		if ( node == NULL )  return NULL;
		node->value = value;

		//If the list is empty
		if ( list->length == 0 )
		{
			list->head = list->tail = node;
			node->prev = node->next = NULL;
		}

		else
		{
			node->prev = NULL;
			node->next = list->head;

			list->head->prev = node;
			list->head = node;
		}

		list->length++;
		return list;

	}


	//Add node after the list tail
	dlist* list_add_node_tail(dlist* list, void* value)
	{

		//Create a new node
		list_node* node = (list_node*)malloc(sizeof(list_node));
		if ( node == NULL )  return NULL;
		node->value = value;

		if ( list->length == 0){
			list->head = list->tail = node;
			node->prev = node->next = NULL;
		}
		else{
			node->prev = list->tail;
			node->next = NULL;
			list->tail->next = node;
			list->tail = node;
		}

		list->length++;
		return list;
	}


	//Node deletion
	void list_del_node (dlist* list, list_node* node)
	{
		//First,figure out whether the node has a direct prev
		if ( node->prev )
			node->prev->next = node->next;
		else
			list->head = node->next;


		//Seconde,figure out whether the node has a direct next
		if ( node->next )
			node->next->prev = node->prev;
		else
			list->tail = node->prev;

		//Thirdly, free the node
		free(node);
		list->length--;
	}


	//Get the list head node data
	void* list_get_value_head( dlist* list )
	{
		if ( list->head == NULL )  return NULL;

		//Create a temp var store the data
		void* value = list->head->value;
		//Delete the node 
		list_del_node(list,list->head);
		return value;
	}

	//Get the list tail node data
	void* list_get_value_tail( dlist* list )
	{
		if ( list->tail == NULL )  return NULL;

		//Create a temp var store the data
		void* value = list->tail->value;
		//Delete the node 
		list_del_node(list,list->tail);
		return value;
	}


	//Empty the list
	void list_empty( dlist* list)
	{
		unsigned long length;
		list_node* curr;
		list_node* next;
		curr = list->head;
		length = list->length;

		while( length-- )
		{
			next = curr->next;
			free(curr);
			curr = next;
		}

		list->head = list->tail = NULL;
		list->length = 0;
	}



	//Release the list
	void list_release( dlist* list )
	{
		list_empty(list);
		free(list);
	}


	//Iteration
	#define LIST_START_HEAD 0
	#define LIST_START_TAIL 1

	//Iteration struct
	typedef struct list_iter
	{
		list_node* next;
		int direction;
	} list_iter;




	//Create Iterator
	list_iter* list_get_iterator ( dlist* list , int direction )
	{

		list_iter* iter = (list_iter* )malloc(sizeof(list_iter));
		if ( iter == NULL )  return NULL;

		//Figure the iter direction
		if ( direction == LIST_START_HEAD )
			iter->next = list->head;
		else
			iter->next = list->tail;
		iter->direction = direction;

		return iter;
	}

	//Get the Iterator next node value
	void* list_next ( list_iter* iter )
	{
		list_node* curr = iter->next;
		if ( curr == NULL )  return NULL;

		if ( iter->direction == LIST_START_HEAD )
			iter->next = curr->next;
		else
			iter->next = curr->prev;

		return curr->value;
	}


	//Free the memory of the iterator
	void list_release_iterator(list_iter* iter)
	{
		free(iter);
	}




	//Test the code 
/* 测试数据 */
    char a = 'A';
    char b = 'B';
    char c = 'C';

    /* 创建链表 */
    dlist *list = create_list(); 
    
    /* 测试空表是否报错 */
    printf("-----测试空链表是否报错\n");
    printf("%p\n", list_get_value_head(list));
    printf("%p\n", list_get_value_tail(list));

    /* 表头添加数据 */
    list_add_node_head(list, &a);
    list_add_node_head(list, &b);
    /* 表尾添加数据 */
    list_add_node_tail(list, &c);
    list_add_node_tail(list, &a);

    printf("-----此时链表长度：%d\n", list->length);
    printf("-----测试表头出队-----\n");
    /* 先出队两次，测试表头出队 */
    while (list->length>2)
    {   
        printf("%c\n", *(char*)list_get_value_head(list));
    }
    printf("-----测试表尾出队-----\n");
    /* 测试表尾出队 */
    while (list->length)
    {   
        printf("%c\n", *(char*)list_get_value_tail(list));
    }

    /* 添加数据 */
    list_add_node_head(list, &a);
    list_add_node_head(list, &b);
    list_add_node_head(list, &c);

    /* 创建一个正向迭代器迭代器 */
    list_iter *iter = list_get_iterator(list, LIST_START_HEAD);
    /* 测试迭代器 */
    printf("-----测试迭代器-------\n");
    printf("%c\n", *(char *)list_next(iter));
    printf("%c\n", *(char *)list_next(iter));

    /* 释放迭代器 */
    list_release_iterator(iter);

    /* 清除链表节点 */
    list_empty(list);
    
    printf("-----测试空链表是否报错\n");
    printf("%p\n", list_get_value_head(list));
    printf("%p\n", list_get_value_tail(list));

    /* 释放链表 */
    list_release(list);




	return 0;
}