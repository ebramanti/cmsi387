/**
 * A test harness for running solutions to the bounded buffer problem.
 */
#include <pthread.h>
#include <stdio.h>

#include "bb-sync.h"

// Number of philosophers and chopsticks.
#define NUM 5

#define THINKING 0
#define HAS_CHOPSTICK 1
#define EATING 2

int chopstick_state[NUM];
int philosopher_state[NUM];

pthread_t philosopher[NUM];
pthread_mutex_t chopsticks[NUM];

/* The test harness defines the expected interfaces. */
void *produce(int produceBound);
void *consume(int consumeBound);

/**
 * Thread runner for the consumer.
 */
void *chopstickRunner(void *arg, void *arg2) {
    //printf("Starting consumer\n");
    //printf("Ending consumer\n");
    pthread_exit(NULL);
}

/**
 * Overall driver program.
 */
int main(int argc, char** argv) {
    printf("Starting Dining Philosophers Program...\n");

    /* Initialize the synchronization primitives. */
    initSync();

    /* Start the threads. */

    for (int i = 0; i < NUM; i++) {
        philosopher_state[i] = THINKING;
        chopstick_state[i] = 0;
        pthread_create(&philosophers[i], NULL,/*need value here*/, i);
        pthread_mutex_init(&chopsticks[i], NULL);
    }


    /*pthread_t prod, cons;
    pthread_create(&prod, NULL, prodRunner, (void *)2);
    pthread_create(&cons, NULL, consRunner, (void *)3); */

    /* Not really needed, since we'll pretty much run forever... */
    for (int i = 0; i < NUM; i++) {
        pthread_join(philosophers[i], NULL);
    }

    /* We won't really get here, but to avoid any warnings... */
    return 0;
}
