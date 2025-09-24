//Simple C prog to show mutext usage

#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 4
#define NUM_INCREMENTS 100000


int counter = 0
pthread_mutext_t lock;

void increment(void *p)
{
  pthread_mutex_lock(&lock)
  if (counter <= NUM_INCREMENTS)
    counter += 1
  pthread_mutex_unlock(&lock)
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Initialize the mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex init failed\n");
        return 1;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    printf("Final counter value: %d\n", counter); 
    // Expected: NUM_THREADS * NUM_INCREMENTS = 400000
    return 0;
}
