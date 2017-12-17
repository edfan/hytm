/* cuckoo.h: THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT MODIFY IT OR YOUR
 * CHANGES MAY GET CLOBBERED.
 */
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

typedef struct cuckoo_t cuckoo_t;

/** Create a new locked cuckoo hash table with the given capacity, threshold,
 *  and probe size.
 */
cuckoo_t* cuckoo_create(long long capacity, long long threshold, long long probe_size);

/** Free a Cuckoo hash table.  This function is not thread-safe, and the
 *  caller should ensure it is the only thread acting on the table.
 */
void cuckoo_destroy(cuckoo_t* cuckoo);

/** Return true iff cuckoo contains x.
 */
char cuckoo_contains(cuckoo_t* cuckoo, long long x);

/** Add x to cuckoo if it isn't already present.  Return true iff it succeeds.
 */
char cuckoo_add(cuckoo_t* cuckoo, long long x);

/** Remove x from cuckoo if it exists.  Return true iff it succeeds.
 */
char cuckoo_remove(cuckoo_t* cuckoo, long long x);

#ifdef __cplusplus
} // extern "C"
#endif
