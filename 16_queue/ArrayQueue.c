
// gcc -fsanitize=address -fno-omit-frame-pointer  -g src.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	

	//Define array queue 
	const int capacity = 20;    //Array capactiy
	char array[capacity];  //Array for queue
	int n = capacity;
	int head = 0;         //Queue head
	int tail = 0;         //Queue tail


	//Create queue
	char* create_queue()
	{
		// array[capacity] = {0};
		 void* arr = memset(array, 0, capacity);

		return arr;
	}

		//Enqueue
		char* enqueue (char* queue, char data)
		{
			if ( tail == n)    //Queue is full
				return;
			queue[tail] = data;
			tail++;

			return queue;
		}

		//Dequeue
		char dequeue (char* queue)
		{
			if ( head == tail)
				return ;
			char ret = queue[head];
			head++;

			return ret;
		}


		//Empty the queue
		void Empty_queue(char* queue)
		{
			head = 0;
			tail = 0;

			return;
		}


	//Test the code
	char a = 'a';
	char b = 'b';
	char c = 'c';

	char* qe = create_queue();
	printf("%p\n",dequeue(qe) );

	enqueue(qe,a);
	enqueue(qe,c);
	enqueue(qe,b);

	while( head != tail)
	{
		printf("%c\n",dequeue(qe) );
	}
	enqueue(qe,c);
	enqueue(qe,c);

	Empty_queue(qe);

	printf("%p\n",dequeue(qe));


	return 0;
}