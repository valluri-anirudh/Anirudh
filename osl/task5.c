#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 2

sem_t mutex, wrt;
int data = 0;
int readers_count = 0;

void *reader(void *arg) {
    int id = *(int *)arg;
    while (1) {
        usleep(1000000); // Sleep for 1 second to simulate reading time
        sem_wait(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&wrt);
        }
        sem_post(&mutex);

        printf("Reader %d reads data: %d\n", id, data);

        sem_wait(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&wrt);
        }
        sem_post(&mutex);
    }
}

void *writer(void *arg) {
    int id = *(int *)arg;
    while (1) {
        usleep(2000000); // Sleep for 2 seconds to simulate writing time
        sem_wait(&wrt);
        data++;
        printf("Writer %d writes data: %d\n", id, data);
        sem_post(&wrt);
    }
}

int main() {
    pthread_t readers[NUM_READERS], writers[NUM_WRITERS];

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    int i;
    int reader_ids[NUM_READERS];
    int writer_ids[NUM_WRITERS];

    for (i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    for (i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    for (i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
