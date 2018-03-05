/* software_tran.h: THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT MODIFY IT OR YOUR
 * CHANGES MAY GET CLOBBERED.
 */
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

void TAS_lock(int* m_locked);

void TAS_unlock(int* lock);

char TAS_try_acquire_lock(int* m_locked);

char TAS_not_taken(int* lock);

void hybrid_xbegin();

void hybrid_xend();

#ifdef __cplusplus
} // extern "C"
#endif
