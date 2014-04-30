/**
 * A test harness for running solutions to the bounded buffer problem.
 */
#include <pthread.h>
#include <stdio.h>

#define NUM 5 // Number of philosophers and chopsticks.
#define THINKING 0

int chopstick_state[NUM];
int philosopher_state[NUM];

pthread_t philosopher[NUM];
pthread_mutex_t chopsticks[NUM];

/**
 * Thread runner for the philosophers.
 */
void *chopstickRunner(void *philosophers, int *philosopherState, void *chopsticks, int *chopstickState) {
    printf("Executing philosopher process.\n");
    run_philosopher(philosophers, philosopherState, chopsticks, chopstickState);
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
        pthread_create(&philosophers[i], NULL,chopstickRunner, i);
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    /* Not really needed, since we'll pretty much run forever... */
    for (int i = 0; i < NUM; i++) {
        pthread_join(philosophers[i], NULL);
    }

    /* We won't really get here, but to avoid any warnings... */
    return 0;
}
