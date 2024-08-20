#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

#define N 5
#define thinking 0
#define hungry 1
#define eating 2
#define left (ph_num+4)%N
#define right (ph_num+1)%N

sem_t mutex;
sem_t s[N];

void *philosopher(void *num);
void take_fork(int);
void put_fork(int);
void teet(int);

int state[N] = {thinking, thinking, thinking, thinking, thinking};
int phil_num[N] = {0, 1, 2, 3, 4};

int main() {
    int i;
    pthread_t thread_id[N];

    sem_init(&mutex, 0, 1);
    for(i = 0; i < N; i++) {
        sem_init(&s[i], 0, 0);
    }
    for(i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL, philosopher, &phil_num[i]);
        printf("Philosopher %d is thinking \n", i + 1);
    }
    for(i = 0; i < N; i++) {
        pthread_join(thread_id[i], NULL);
    }
}

void *philosopher(void *num) {
    while(1) {
        int *i = num;
        sleep(1);
        take_fork(*i);
        sleep(1);
        put_fork(*i);
    }
}

void take_fork(int ph_num) {
    sem_wait(&mutex);
    state[ph_num] = hungry;
    printf("Philosopher %d is hungry\n", ph_num + 1);
    teet(ph_num);
    sem_post(&mutex);
    sem_wait(&s[ph_num]);
    sleep(1);
}

void teet(int ph_num) {
    static int count = 0;
    if(state[ph_num] == hungry && state[left] != eating && state[right] != eating) {
        state[ph_num] = eating;
        printf("Philosopher %d takes fork %d and %d\n", ph_num + 1, left + 1, ph_num + 2);
        printf("Philosopher %d is eating\n", ph_num + 1);
        sem_post(&s[ph_num]);
        count++;
    }
    if(count == 5) {
        exit(1);
    }
}

void put_fork(int ph_num) {
    sem_wait(&mutex);
    state[ph_num] = thinking;
    printf("Philosopher %d putting fork %d and %d down\n", ph_num + 1, left + 1, ph_num + 1);
    printf("Philosopher %d is thinking\n", ph_num + 1);
    teet(left);
    teet(right);
    sem_post(&mutex);
}
