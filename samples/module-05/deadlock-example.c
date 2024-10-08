#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Declare two mutexes
pthread_mutex_t lock1;
pthread_mutex_t lock2;

// Thread function for Thread 1
void *thread1_func(void *arg) {
    // Try to acquire lock1 first
    pthread_mutex_lock(&lock1);
    printf("Thread 1: Acquired lock1, waiting for lock2...\n");

    // Simulate some work with sleep
    sleep(1);

    // Try to acquire lock2
    pthread_mutex_lock(&lock2);
    printf("Thread 1: Acquired lock2!\n");

    // Release locks
    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);

    return NULL;
}

// Thread function for Thread 2
void *thread2_func(void *arg) {
    // Try to acquire lock2 first
    pthread_mutex_lock(&lock2);
    printf("Thread 2: Acquired lock2, waiting for lock1...\n");

    // Simulate some work with sleep
    sleep(1);

    // Try to acquire lock1
    pthread_mutex_lock(&lock1);
    printf("Thread 2: Acquired lock1!\n");

    // Release locks
    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Initialize the mutexes
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);

    // Create two threads
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutexes
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);

    printf("Program completed.\n");
    return 0;
}
