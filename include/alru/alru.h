#ifndef ALRU_H
#define ALRU_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdlib.h>
#include "common.h"

typedef struct alru alru_t;
typedef ALRUvoid (alru_evict_f)(alru_t *alru, alru_uint64_t index, alru_uint64_t value);

struct alru {
  alru_uint64_t collisions;
  alru_uint64_t buckets;
  alru_uint64_t size;
  alru_uint64_t max;
  alru_uint64_t **cache;
  ALRUvoid *alloc;
};

/**
 * Initializes an already allocated `alru_t *' pointer with
 * a max cache size. If an already
 */
ALRU_EXPORT ALRUboolean
alru_init(alru_t *alru, const alru_uint64_t max);

/**
 */
ALRU_EXPORT ALRUboolean
alru_set(alru_t *alru, const alru_uint64_t index, const alru_uintptr_t value);

/**
 */
ALRU_EXPORT alru_uintptr_t
alru_get(alru_t *alru, const alru_uint64_t index);

/**
 */
ALRU_EXPORT ALRUboolean
alru_clear(alru_t *alru);

/**
 * Allocates and returns a new `alru_t *' pointer.
 */
inline ALRU_EXPORT alru_t *
alru(const alru_uint64_t max) {
  alru_t *self = (alru_t *) malloc(sizeof(alru));
  if (self) {
    if (ALRU_FALSE == alru_init(self, max)) {
      free(self);
      self = 0;
    }
  }
  return self;
}

#if defined(__cplusplus)
}
#endif

#endif
