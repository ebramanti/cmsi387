/**
 * Philosopher library implementation.
 */
#include "utility.h"

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define NUM_OF_PHILS 5

#define THINKING 0
#define HUNGRY 1
#define EATING 2

void display_philosopher() {
    for (int i = 0; i < NUM_OF_PHILS; i++) {
        if (philosopher_state[i] == THINKING) {
            printf("THINKING ");
        } else if (philosopher_state[i] == HUNGRY) {
            printf("HUNGRY ");
        } else if (philosopher_state[i] == EATING) {
            printf("EATING ");
        }
    }
}

void think(int philosopher) {
    randomWait(NUM_OF_PHILS);
    philosopher_state[philosopher] = HUNGRY;
}

void hungry(int philosopher) {
    getChopstick(philosopher);
    getChopstick((philosopher + 1) % NUM_OF_PHILS);
    philosopher_state[philosopher] = EATING;
    randomWait(NUM_OF_PHILS);
}

void eating(int philosopher) {
    releaseChopstick(philosopher);
    releaseChopstick((philosopher + 1) % NUM_OF_PHILS);
    philosopher_state[philosopher] = THINKING;
}

int getChopstick(int chopstick) {
    if (chopstick > NUM_OF_PHILS) {
        printf("Index out of bounds.");
        return -1;
    }
    else if (chopstickState[chopstick] == 1) {
        printf("Chopstick %d already taken.", chopstick);
        return -1;
    }
    pthread_mutex_lock(&chopsticks[chopstick]);
    chopsticks[chopstick] += 1;
    return 0;
}

int releaseChopstick(int chopstick) {
    if (chopstick > NUM_OF_PHILS) {
        printf("Index out of bounds.");
        return -1;
    }
    else if (chopstickState[chopstick] == 0) {
        printf("Chopstick %d not taken.", chopstick);
        return -1;
    }
    pthread_mutex_unlock(&chopsticks[chopstick]);
    chopsticks[chopstick] -= 1;
    return 0;
}

void run_philosopher(int philosopher) {
    display_philosopher();
    int* currentState = philosopher_state[philosopher];
    // STILL UNIMPLEMENTED.
    while (1) {
        display_philosopher();
        if (currentState == THINKING) {
            think(philosopher);
        } else if (currentState == HUNGRY) {
            hungry(philosopher);
        } else if (currentState == HAS_CHOP) {
            has_one_chop(philosopher);
        } else if (currentState == EATING) {
            eating(philosopher);
        } else {
            // THIS IS BAD.
        }
    }
}
