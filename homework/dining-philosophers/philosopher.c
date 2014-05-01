/**
 * Philosopher library implementation.
 */
#include "utility.h"

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define NUM 5

#define THINKING 0
#define HUNGRY 1
#define HAS_CHOP 2
#define EATING 3

void display_philosopher() {
    // TODO for printing out state of philosophers.
}

void think(int philosopher) {
    randomWait(NUM);
    philosopher_state[philosopher] = HUNGRY;
}

void hungry(int philosopher) {
    randomWait(NUM);
    getChopstick(philosopher);
    philosopher_state[philosopher] = HAS_CHOP;
}

void has_one_chop(int philosopher) {
    getChopstick(philosopher);
    if (philosopher_state[philosopher] != THINKING) {
        getChopstick((philosopher + 1) % NUM);
        if (philosopher_state[philosopher] == HAS_CHOP) {
            philosopher_state[philosopher] = EATING;
            randomWait(NUM);
        }
    }
}

void eating(int philosopher) {
    releaseChopstick(philosopher);
    releaseChopstick((philosopher + 1) % NUM);
    philosopher_state[philosopher] = THINKING;
}

int getChopstick(int chopstick) {
    if (chopstick > NUM) {
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
    if (chopstick > NUM) {
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
