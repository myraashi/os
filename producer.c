#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

#define max 5
#define size 5

sem_t empty, full;
pthread_mutex_t mutex;
int in = 0, out = 0, buffer[size];

void *producer(void* pno)
{
	int item;
	for(int i=0;i<max;i++)
	{
		item = rand()%100;
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in] = item;
		printf("PRODUCER %d: Inserted the item %d at %d\n",*((int*)pno),buffer[in],in);
		in = (in+1)%size;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}

void *consumer(void *cno)
{
for(int i = 0;i<max;i++)
{
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	int item = buffer[out];
	printf("CONSUMER %d: Removed item %d from %d\n",*((int*)cno),buffer[out], out);
	out = (out+1)%size;
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
}
}

int main()
{
pthread_t pro[5], con[5];
pthread_mutex_init(&mutex, NULL);
sem_init(&empty, 0, size);
sem_init(&full, 0,0);
int a[] = {1,2,3,4,5};

for(int i = 0;i<max;i++)
{
pthread_create(&pro[i],NULL,(void*)producer,(void*)&a[i]);
pthread_create(&con[i],NULL,(void*)consumer,(void*)&a[i]);
}
for(int i = 0;i<max;i++)
{
pthread_join(pro[i],NULL);
pthread_join(con[i], NULL);
}
pthread_mutex_destroy(&mutex);
sem_destroy(&empty);
sem_destroy(&full);
return 0;
}
