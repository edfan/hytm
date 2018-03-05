#include <immintrin.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/param.h>
#pragma GCC target("rtm")
int THRESHOLD= 4;
typedef  uint64_t mutex;
static mutex  lock = 0;
bool try_acquire_lock(mutex * lock ){
    return __sync_bool_compare_and_swap(lock, 0, 1);
};
void release_lock(mutex * lock ){
    __sync_bool_compare_and_swap(lock, 1, 0);
};
bool lock_not_taken(mutex * lock ){
    return *lock == 0;
};
void our_xbegin() {
    start:
    for (int i = 0; i < THRESHOLD; ++i) {
        if (_xbegin() == _XBEGIN_STARTED) {
            while (!lock_not_taken(&lock));
            return;
        }
    }
    if(try_acquire_lock(&lock)) {

        return;
    }
    goto start;

}

void our_xend() {
    if (lock_not_taken(&lock))
        _xend();
    else
        release_lock(&lock);
}