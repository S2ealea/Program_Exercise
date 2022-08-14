#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./array_queue.h"

array_queue* array_queue_create(int size)
{
	array_queue* queue = (array_queue*)malloc(sizeof(array_queue));
	if (queue == NULL)  return NULL;
	queue->array = (int*)malloc(sizeof(int)*size);
	if (queue->array == NULL)
	{
		free(queue);
		return NULL;
	}
	queue->size = size;
	queue->num = 0;
	queue->head = 0;
	queue->tail = 0;

	return queue;
}

void array_queue_destory(array_queue* queue)
{
	if (queue == NULL)
		return;

	if(queue->array != NULL)
	{
		free(queue->array);
	}

	free(queue);
	return;
}


//Enqueue 
int array_queue_enqueue(array_queue* queue,int data)
{
	//If the queue is empty or full ,return -1
	if ((queue == NULL) || array_queue_is_full(queue))
		return -1;

	queue->num++;
	queue->array[queue->tail] = data;
	queue->tail = queue->tail + 1;

	return 0;
}

//Dequeue
int array_queue_dequeue (array_queue* queue, int* data)
{
	//If the queue is empty or full, return -1
	if ((queue == NULL) || (data == NULL) || (array_queue_is_empty(queue)))
		return -1;

	*data = queue->array[queue->head];
	queue->num--;
	queue->head = (queue->head + 1);

	return 0;	
}

void array_queue_dump(array_queue* queue)
{
	int i = 0;
	int pos = 0;

	if ((queue == NULL) || (array_queue_is_empty(queue)))
	{
		printf("\r\n queue is empty");
		return ;
	}

	printf("\r\n size:%d,num:%d,head:%d,tail:%d",queue->size,queue->num,queue->head,queue->tail);

	for (int i = 0; i < queue->num; i++)
	{
		pos = (queue->head + i);
		printf("\r\n array[%d] = %d",pos,queue->array[pos]);
	}

	return;

}


int main(int argc, char const *argv[])
{
	int i = 0;
	int ret = 0;
	int data = 0;
	array_queue* queue = NULL;

	queue = array_queue_create(4);
	if (queue == NULL)
	{
		printf("\r\n queue is create failed.");
		return 0;
	}


	//When the queue is empty ,dequeue return failure
	ret = array_queue_dequeue(queue,&data);
	if (ret != 0)
	{
		printf("\r\n queue %d dequeue failed.",ret);

	}

	//Now the queue size is 4, enqueue 5 element, the last will
	// return a failure
	for (int i = 0; i < 5; i++)
	{
		ret = array_queue_enqueue(queue,i);
		if (ret != 0)
		{
			printf("\r\n queue %d enqueue failed.",i);
		}

	}

	array_queue_dump(queue);

	ret = array_queue_dequeue(queue,&data);
	if (ret != 0)
	{
		printf("\r\n queue %d dequeue failed.",i);

	}

	printf("\r\n queue %d dequeue.",data);
	array_queue_dump(queue);

	data = 5;
	printf("\r\n queue %d enqueue.",data);
	ret = array_queue_enqueue(queue,data);
	if (ret != 0)
	{
		printf("\r\n queue %d enqueue." ,data);
	}

	array_queue_dump(queue);

	array_queue_destory(queue);


	return 0;
}