#include <stdio.h>
#include <sys/param.h>
#include <pthread.h>
static volatile int counter;
void * increment_counter(int i ){
    printf("size of unsigned %d ", sizeof(unsigned int ));
    int INCRMENT_COUNT = 500;
    for(int i = 0; i < INCRMENT_COUNT; i++ ){
        our_xbegin();
        for(int i = 0; i < INCRMENT_COUNT; i++){
            counter++;
        }
        our_xend();
    }

}
int main() {
    pthread_t threads [8];

    for(int i = 0; i < 8; i++){
        pthread_create(&threads[i], NULL, increment_counter,
                       (void*)i);
    }
    for(int i = 0; i < 8; i++){
       pthread_join(threads[i], NULL);
    }

    printf("counter value %d \n", counter);
    return 0;
}


