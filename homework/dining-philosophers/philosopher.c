/**
 * An implementation of dining philosophers.
 */
#include "utility.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_PHILS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

pthread_t philosophers[NUM_OF_PHILS];
pthread_mutex_t chopsticks[NUM_OF_PHILS];
pthread_mutex_t display_mutex;
int philosopher_state[NUM_OF_PHILS];
int chopstick_state[NUM_OF_PHILS];
int canPrint;

const char* chopstickAvailable = "|";
const char* chopstickTaken = "x";

// JD: This display approach is OK but is missing one important state---
//     who is holding what chopstick.  Very important for ensuring that
//     your program is indeed running correctly.
//
//     (as you will see in my later notes)
void display_philosopher() {
    pthread_mutex_lock(&display_mutex);
    canPrint = 0;
    // JD: ^^^^^OK, so now this one is overkill.  Put things in context:
    //     the purpose of *this* lock is to make sure that display_philosopher
    //     doesn't print on top of itself.  You'll kinda know if it isn't
    //     working, and in the end it is part of the scaffolding for the
    //     program, not the dining philosophers system itself.  So, no need
    //     for canPrint.
    if (canPrint == 1) {
        printf("Illegal state detected in printing.\n");
        exit(-1);
    }
    for (int i = 0; i < NUM_OF_PHILS; i++) {
        const char* cs = chopstick_state[i] == 0 ? chopstickAvailable : chopstickTaken;
        int currentState = philosopher_state[i];
        if (currentState == THINKING) {
            printf("%s THINKING ", cs);
        } else if (currentState == HUNGRY) {
            printf("%s HUNGRY ", cs);
        } else if (currentState == EATING) {
            printf("%s EATING ", cs);
        }
    }
    printf("\n");
    canPrint = 1;
    pthread_mutex_unlock(&display_mutex);
}

int releaseChopstick(int chopstick) {
    if (chopstick > NUM_OF_PHILS) {
        printf("Index out of bounds.\n");
        exit(-1);
    } // JD: Why am I seeing "}" and "else if" on different lines so often now?
    else if (chopstick_state[chopstick] == 0) {
        printf("Chopstick %d not taken.\n", chopstick);
        exit(-1);
    }
    chopstick_state[chopstick] -= 1;
    pthread_mutex_unlock(&chopsticks[chopstick]);
    return 0;
}

int getChopstick(int chopstick) {
    pthread_mutex_lock(&chopsticks[chopstick]);
    if (chopstick > NUM_OF_PHILS) {
        printf("Index out of bounds.\n");
        exit(-1);
    }
    else if (chopstick_state[chopstick] == 1) {
        printf("Chopstick %d already taken.\n", chopstick);
        exit(-1);
    }
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
        display_philosopher(); // Implemented check for concurrency so this won't print multiple times.
        if (philosopher_state[index] == EATING) {
            eating(index);
        } else if (philosopher_state[index] == THINKING) {
            think(index);
        } else if (philosopher_state[index] == HUNGRY) {
            hungry(index);
        } else {
            printf("Unexpected state detected. Exiting program.\n");
            exit(-1);
        }
    }
}

/**
 * Overall driver program.
 */
int main () {
    printf("Starting Dining Philosophers Program...\n");
    /* Create threads and initialize mutexes. */
    canPrint = 1;
    pthread_mutex_init(&display_mutex, NULL);
    int index[NUM_OF_PHILS];
    for (int i = 0; i < NUM_OF_PHILS; i++) {
        index[i] = i;
        philosopher_state[i] = THINKING;
        chopstick_state[i] = 0;
        pthread_create(&philosophers[i], NULL, run_philosopher, &index[i]);
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    /* Not really needed, since we'll pretty much run forever... */
    // JD: Be careful what you say---have you *tried* to comment this out?  O_o
    for (int i = 0; i < NUM_OF_PHILS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    /* We won't really get here, but to avoid any warnings... */
    return 0;
}
