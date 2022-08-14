#ifndef __QUEUE_H__
#define __QUEUE_H__

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

	queue* create_queue();
	queue* enqueue (queue* queue, void* data);
	queue* dequeue (queue* queue);
	void Empty_queue(queue* queue);
	void release_queue( queue* queue);






#endif