/**
 * Philosopher library implementation.
 */
#include "utility.h"

#include <pthread.h>
#include <stdio.h>

#define THINKING 0
#define HUNGRY 1
#define HAS_CHOP 2
#define HAS_TWO_CHOP 3
#define EATING 4


void get_chopstick() {
    // USE THIS.
    pthread_mutex_lock();
}

void display_philosopher() {
    // TODO for printing out state of philosophers.
}

void run_philosopher(void* philosopher, void* state, void* chopsticks, void* chopstickState) {

    int id = 0; // TODO IMPLEMENT AN ID
    while (1) {
        if (state[id] == THINKING) {
            thinking(id);
        } else if (state[id] == HAS_CHOPSTICK) {
            has_chopstick(id);
        } else if (state[id] == EATING) {
            eating(id);
        }
    }
}
