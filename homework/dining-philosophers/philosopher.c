/**
 * Philosopher library implementation.
 */
#include "utility.h"

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define THINKING 0
#define HUNGRY 1
#define HAS_CHOP 2
#define HAS_TWO_CHOP 3
#define EATING 4

void display_philosopher() {
    // TODO for printing out state of philosophers.
}

void think() {
    // TODO
}

void hungry() {
    // TODO
}

void has_one_chop() {
    // TODO
}

void has_two_chop() {
    // TODO
}

void eating() {
    // TODO
}

void run_philosopher(void* philosopher, void* state, void* chopsticks, void* chopstickState) {
    // NOT DONE. An outline for how while loop should work.
    display_philosopher();
    int currentState = state[philosopher]
    while (1) {
        display_philosopher();
        if (currentState == THINKING) {
            think();
        } else if (currentState == HUNGRY) {
            hungry();
        } else if (currentState == HAS_CHOP) {
            has_one_chop();
        } else if (currentState == HAS_TWO_CHOP) {
            has_two_chop();
        } else {
            eating();
        }
    }
}
