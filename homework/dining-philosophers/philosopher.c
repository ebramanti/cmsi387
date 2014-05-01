/**
 * An implementation of dining philosophers.
 */
#include "utility.h"
#include <pthread.h>
#include <stdio.h>

#define NUM_OF_PHILS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

pthread_t philosophers[NUM_OF_PHILS];
pthread_mutex_t chopsticks[NUM_OF_PHILS];
int philosopher_state[NUM_OF_PHILS];
int chopstick_state[NUM_OF_PHILS];

void display_philosopher() {
    for (int i = 0; i < NUM_OF_PHILS; i++) {
        int currentState = philosopher_state[i];
        if (currentState == THINKING) {
            printf("THINKING ");
        } else if (currentState == HUNGRY) {
            printf("HUNGRY ");
        } else if (currentState == EATING) {
            printf("EATING ");
        }
    }
    printf("\n");
}

int releaseChopstick(int chopstick) {
    if (chopstick > NUM_OF_PHILS) {
        printf("Index out of bounds.\n");
        return -1;
    }
    else if (chopstick_state[chopstick] == 0) {
        printf("Chopstick %d not taken.\n", chopstick);
        return -1;
    }
    pthread_mutex_unlock(&chopsticks[chopstick]);
    chopstick_state[chopstick] -= 1;
    return 0;
}

int getChopstick(int chopstick) {
    if (chopstick > NUM_OF_PHILS) {
        printf("Index out of bounds.\n");
        return -1;
    }
    else if (chopstick_state[chopstick] == 1) {
        printf("Chopstick %d already taken.\n", chopstick);
        return -1;
    }
    pthread_mutex_lock(&chopsticks[chopstick]);
    chopstick_state[chopstick] += 1;
    return 0;
}

void think(int philosopher) {
    randomwait(NUM_OF_PHILS);
    philosopher_state[philosopher] = HUNGRY;
}

void hungry(int philosopher) {
    getChopstick(philosopher);
    getChopstick((philosopher + 1) % NUM_OF_PHILS);
    philosopher_state[philosopher] = EATING;
    randomwait(NUM_OF_PHILS);
}

void eating(int philosopher) {
    releaseChopstick(philosopher);
    releaseChopstick((philosopher + 1) % NUM_OF_PHILS);
    philosopher_state[philosopher] = THINKING;
}

void* run_philosopher(void* philosopher) {
    int index = *(int*) philosopher;
    while (1) {
        if (philosopher_state[index] == EATING) {
            eating(index);
        } else if (philosopher_state[index] == THINKING) {
            think(index);
        } else if (philosopher_state[index] == HUNGRY) {
            hungry(index);
        } else {
            // THIS IS BAD.
        }
        display_philosopher();
    }
}

/**
 * Overall driver program.
 */
int main () {
    printf("Starting Dining Philosophers Program...\n");
    /* Create threads and initialize mutexes. */
    int index[NUM_OF_PHILS];
    for (int i = 0; i < NUM_OF_PHILS; i++) {
        index[i] = i;
        philosopher_state[i] = THINKING;
        chopstick_state[i] = 0;
        pthread_create(&philosophers[i], NULL, run_philosopher, &index[i]);
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    /* Not really needed, since we'll pretty much run forever... */
    for (int i = 0; i < NUM_OF_PHILS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    /* We won't really get here, but to avoid any warnings... */
    return 0;
}
