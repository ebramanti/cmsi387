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

// JD: This display approach is OK but is missing one important state---
//     who is holding what chopstick.  Very important for ensuring that
//     your program is indeed running correctly.
//
//     (as you will see in my later notes)
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
        // JD: On any kind of horrible error, you shouldn't just return from
        //     the function; you should *exit entirely*.  Otherwise you just
        //     go back to the loop and things just keep on going.
        printf("Index out of bounds.\n");
        return -1;
    }
    // JD: So, this error message appears when I run your program.
    //     BIG PROBLEM---this means that a philosopher tries to
    //     release a chopstick *that is not taken*.  You shouldn't
    //     just return from the function here; you should actually
    //     quit the entire program!
    //
    //     (and the fact that this happens in your program is a
    //     sign that you aren't doing mutual exclusion right)
    else if (chopstick_state[chopstick] == 0) {
        printf("Chopstick %d not taken.\n", chopstick);
        return -1;
    }
    pthread_mutex_unlock(&chopsticks[chopstick]);
    // JD: Don't change the state of a chopstick *outside* of the protected
    //     area!  Done this way, your mutex activities are useless.
    //     This is one reason that you're getting the errors.
    chopstick_state[chopstick] -= 1;
    return 0;
}

int getChopstick(int chopstick) {
    if (chopstick > NUM_OF_PHILS) {
        printf("Index out of bounds.\n");
        return -1;
    }
    // JD: Meanwhile, *this* error check is wrong because it is
    //     in the wrong place.  It is the job of the mutex/semaphore
    //     to ensure that a philosopher does not pick up a chopstick
    //     that is already taken.  Here, you *bail out* if a chopstick
    //     is taken.  That isn't how it's supposed to work.  If you try
    //     to lock a chopstick that is taken, *then the mutex lock will
    //     wait for it*.
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
            // JD: So why is the program quiet?
        }

        // JD: Remember, this is in a thread that is running concurrently with
        //     others.  You may have noticed that the output of display_philosopher()
        //     occasionally interleaves with other display_philosopher() calls.
        //
        //     Better to do your display inside a critical section, so that another
        //     concurrent display_philosopher() does not mix in its output.
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
