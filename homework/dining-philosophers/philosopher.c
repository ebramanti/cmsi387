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
#define NUM 5

void display_philosopher() {
    // TODO for printing out state of philosophers.
}

void think(int philosopher) {
    // TODO
}

void hungry(int philosopher) {
    // TODO
}

void has_one_chop(int philosopher, int chopstick) {
    // TODO
}

void has_two_chop(int philosopher, int chopstick) {
    // TODO
}

void eating(int philosopher) {
    // TODO
}

void run_philosopher(int philosopher) {
    display_philosopher();
    int* currentState = philosopher_state[philosopher];
    // STILL UNIMPLEMENTED.
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
