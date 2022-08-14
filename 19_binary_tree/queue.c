
// gcc -fsanitize=address -fno-omit-frame-pointer  -g src.c

#include <stdio.h>
#include <stdlib.h>



	//Define queue node
	typedef struct queue_node
	{
		struct queue_node* next;
		void* data;
	} queue_node;


	//The queue
	typedef struct queue
	{
		struct queue_node* head;
		struct queue_node* tail;
		int length;		
	} queue;





	//Create queue
	queue* create_queue()
	{
		queue* queue = (struct queue*)malloc(sizeof(struct queue));
		queue_node* node = (struct queue_node*)malloc(sizeof(struct queue_node));
		if ( queue == NULL || node == NULL )  return NULL;

		node->data = NULL;
		node->next = NULL;


		//Init the queue
		queue->head = queue->tail = node;
		queue->length = 0;

		return queue;
	}





		//Enqueue
		queue* enqueue (queue* queue, void* data)
		{
			queue_node* node = (struct queue_node*)malloc(sizeof(queue_node));
			if ( node == NULL ) return NULL;

			node->data = data;

			//Insert the node after the queue tail
			queue->tail->next = node;
			queue->tail = queue->tail->next;

			queue->length++;
			return queue;
		}




		//Dequeue
		void* dequeue (queue* queue)
		{
			queue_node* curr = queue->head->next;

			if (curr == NULL )  return NULL;
			void* data = curr->data;

			queue->head->next = curr->next;


			//Test if only a node in the queue except the head node
			//Avoid the tail point lost
			if (queue->tail == curr )
			{
				queue->tail = queue->head;
			}

			free(curr);
			queue->length--;

			return data;
		}




		//Empty the queue
		void Empty_queue(queue* queue)
		{

			int length = queue->length;
			queue_node* curr;
			queue_node* next;


			//Caution : Preserve the head node
			curr = queue->head->next;
			while(length--)
			{
				next = curr->next;
				free(curr);
				curr = next;
			}

			queue->head->next = next;
			queue->head->data = NULL;
			queue->tail = queue->head;
			queue->length = 0;
		}







         //Release the queue
		void release_queue( queue* queue)
		{
			Empty_queue(queue);
			free(queue->head);
			free(queue);
		}

