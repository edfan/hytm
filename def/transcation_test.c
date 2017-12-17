#include <stdio.h>
#include <sys/param.h>
#include <pthread.h>
#include <assert.h>
#include "software_tran.h"
static volatile int counter;
int INCREMENT_COUNT = 500;
void * increment_counter(){

    for(int i = 0; i < INCREMENT_COUNT; i++ ){
        our_xbegin();
        for(int j = 0; j < INCREMENT_COUNT; j++){
            counter++;
        }
        our_xend();
    }
    return NULL;
}

int main() {
    int NUM_THREADS = 8;
    pthread_t threads [NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, increment_counter,
                       NULL);
    }
    for(int i = 0; i < NUM_THREADS; i++){
       pthread_join(threads[i], NULL);
    }
    assert(counter == INCREMENT_COUNT*INCREMENT_COUNT*NUM_THREADS);
    printf("counter value %d \n", counter);
    return 0;
}


