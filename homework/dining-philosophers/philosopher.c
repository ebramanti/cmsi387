/**
 * Philosopher library implementation.
 */
#include "utility.h"

#include <pthread.h>
#include <stdio.h>


void get_chopstick() {
    // USE THIS.
    pthread_mutex_lock();
}

void display_philosopher() {
    // TODO for printing out state of philosophers.
}

void run_philosopher(void* philosopher, void* state, void* chopsticks, void* chopstickState) {

}
