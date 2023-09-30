#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>  // Para usleep

#define BUFFER_SIZE 15

int index_in = 0, index_out = 0, buffer[BUFFER_SIZE];

sem_t sem_empty, sem_full;

pthread_mutex_t mutex;

void* producer(void* arg) {
	for (unsigned i = 0; i < BUFFER_SIZE * 2; ++i) {
		sem_wait(&sem_empty);
		pthread_mutex_lock(&mutex);
		buffer[index_in] = i;
		printf("Item %d producido en la posicion '%d'\n", i, index_in);
		index_in = (index_in + 1) % BUFFER_SIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&sem_full);
		usleep(rand() % 1000001);
	}
	return NULL;
}

void* consumer(void* arg) {
	for (unsigned i = 0; i < BUFFER_SIZE * 2; ++i) {
		sem_wait(&sem_full);
		pthread_mutex_lock(&mutex);
		int item = buffer[index_out];
		printf("Item %d consumido en la posicion '%d'\n", item, index_out);
		index_out = (index_out + 1) % BUFFER_SIZE;
		pthread_mutex_unlock(&mutex);
		sem_post(&sem_empty);
		usleep(rand() % 1000001);
	}
	return NULL;
}

int main() {
	pthread_t prod_thread, cons_thread;

	sem_init(&sem_empty, 0, BUFFER_SIZE);
	sem_init(&sem_full, 0, 0);
	pthread_mutex_init(&mutex, NULL);

	srand(time(NULL));

	pthread_create(&prod_thread, NULL, producer, NULL);
	pthread_create(&cons_thread, NULL, consumer, NULL);

	pthread_join(prod_thread, NULL);
	pthread_join(cons_thread, NULL);

	sem_destroy(&sem_empty);
	sem_destroy(&sem_full);
	pthread_mutex_destroy(&mutex);

	return 0;
}