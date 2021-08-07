#include <stdio.h>
#include <pthread.h>



// Thread work function1
void *thread1_func (void * arg)
{
	while(1)
	{
		printf("Thread1 is exectuing!\n");
		sleep(1);
	}
	

}

// Thread work function2
void *thread2_func (void * arg)
{
	while(1)
	{
		printf("Thread2 is exectuing!\n");
		sleep(1);
	}
	

}


int main(int argc, char** agrv)
{

    // Create thread 1;
    pthread_t thread1_id;
	pthread_create(&thread1_id, NULL,thread1_func,NULL);
	pthread_detach(thread1_id); // Set thread detach attribute

    // Create thread 2;
    pthread_t thread2_id;
	pthread_create(&thread2_id, NULL,thread2_func,NULL);
	pthread_detach(thread2_id); // Set thread detach attribute


	// // Waitting thread exit
	// pthread_join(thread1_id,NULL);
	// pthread_join(thread2_id,NULL);

	return 0;
}