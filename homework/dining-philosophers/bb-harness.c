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


/**
 * Thread runner for the philosophers.
 */
void *chopstickRunner(void *philosophers) {
    printf("Executing philosopher process.\n");
    run_philosopher(philosophers, philosopher_state);
}

/**
 * Overall driver program.
 */
int main(int argc, char** argv) {
    printf("Starting Dining Philosophers Program...\n");

    /* Create threads and initialize mutexes. */
    for (int i = 0; i < NUM; i++) {
        philosopher_state[i] = THINKING;
        chopstick_state[i] = 0;
        pthread_create(&philosophers[i], NULL,/*need value here*/, i);
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    /* Not really needed, since we'll pretty much run forever... */
    for (int i = 0; i < NUM; i++) {
        pthread_join(philosophers[i], NULL);
    }

    /* We won't really get here, but to avoid any warnings... */
    return 0;
}
