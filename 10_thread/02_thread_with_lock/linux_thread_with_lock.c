#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex_lock;
int cnt = 1000;

// Thread work function1
void *thread1_func (void * arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex_lock);  // Thread lock
		if(cnt > 0) printf("Thread1: %d\n", cnt--);
		else break;
		pthread_mutex_unlock(&mutex_lock); // Unlodk mutex lock
		sleep(1);
	}
    // Unlock mutex
    pthread_mutex_unlock(&mutex_lock);
    printf("Thread1 exit!\n");
    return (void*)0;

	

}

// Thread work function2
void *thread2_func (void * arg)
{
	while(1)
	{
		pthread_mutex_lock(&mutex_lock);  // Thread lock
		if(cnt > 0) printf("Thread2: %d\n", cnt--);
		else break;
		pthread_mutex_unlock(&mutex_lock); // Unlodk mutex lock
		sleep(1);
	}
    // Unlock mutex
    pthread_mutex_unlock(&mutex_lock);
    printf("Thread2 exit!\n");
    return (void*)0;

}


int main(int argc, char** agrv)
{

	// Create and initlize mutex lock
	pthread_mutex_init(&mutex_lock,NULL);

    // Create thread 1;
    pthread_t thread1_id;
	pthread_create(&thread1_id, NULL,thread1_func,NULL);
	// pthread_detach(thread1_id); // Set thread detach attribute

    // Create thread 2;
    pthread_t thread2_id;
	pthread_create(&thread2_id, NULL,thread2_func,NULL);
	// pthread_detach(thread2_id); // Set thread detach attribute


	// Waitting thread exit
	pthread_join(thread1_id,NULL);
	pthread_join(thread2_id,NULL);


	// while(1)
	// {
		
	// }
	// Release mutex lock
	pthread_mutex_destroy(&mutex_lock);

	return 0;
}