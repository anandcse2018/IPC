#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <unistd.h>
int mail=0;
pthread_mutex_t mutex;
void* print()
{
	/*printf("Ananad Maurya : %d\n",getpid());
	sleep(3);
	printf("Aman Maurya : %d\n",getpid());*/
	for(int i=0; i<1000; i++)
	{
		pthread_mutex_lock(&mutex);
		mail++;
		pthread_mutex_unlock(&mutex);
	}
}
int main(int argc, char *argv[])
{
	int n=4;
	pthread_t t[n];
	pthread_mutex_init(&mutex,NULL);
    for(int i=0; i<n; i++)
    {
    	pthread_create(t+i,NULL,&print,NULL);
    }
    for(int i=0; i<n; i++)
    {
    	pthread_join(t+i,NULL);
    }
	pthread_mutex_destroy(&mutex);
	printf("Total Mails : %d\n",mail);
	return 0;
}