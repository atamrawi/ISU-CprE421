#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// Global counter and mutex
int counter;
pthread_mutex_t counterMutex;

void *IncreaseCounter(void *args) {
    // Lock the mutex before accessing the counter
    pthread_mutex_lock(&counterMutex);
    
    counter += 1;
    usleep(1);
    printf("Thread %lu has counter value %d\n", (unsigned long)pthread_self(), counter);
    
    // Unlock the mutex after updating the counter
    pthread_mutex_unlock(&counterMutex);
    
    return NULL;
}

int main() {
    pthread_t p[10];
    // Initialize the mutex before creating threads
    pthread_mutex_init(&counterMutex, NULL);

    for (int i = 0; i < 10; ++i) {
        pthread_create(&p[i], NULL, IncreaseCounter, NULL);
    }
    for (int i = 0; i < 10; ++i) {
        pthread_join(p[i], NULL);
    }

    // Destroy the mutex after threads are done
    pthread_mutex_destroy(&counterMutex);

    return 0;
}
