#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

typedef struct _array_queue
{
	int size;    //Queue size
	int num;     //Current elements number
	int head;    //Queue head
	int tail;    //Queue tail
	int* array;   //Array for data storage	
} array_queue;

#define array_queue_is_empty(array_queue) (array_queue->num == 0)
#define array_queue_is_full(array_queue) ((array_queue->num) == (array_queue->size))



#endif