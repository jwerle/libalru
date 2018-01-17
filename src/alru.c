#include <alru/alru.h>
#include <stdlib.h>
#include <string.h>
#include "crc16.h"

#define DEFAULT_COLLISIONS 4
#define BUCKET_MAX 0xffff

// adapted from https://github.com/mafintosh/array-lru/blob/master/index.js
static alru_uint64_t
factorof(alru_uint64_t n, alru_uint64_t factor);

// adapted from https://github.com/mafintosh/array-lru/blob/master/index.js
static alru_uint64_t
factorof2(alru_uint64_t n);

alru_t *
alru(alru_uint64_t collisions, alru_uint64_t max) {
  alru_t *self = (alru_t *) malloc(sizeof(alru));
  if (self) {
    if (ALRU_FALSE == alru_init(self, collisions, max)) {
      free(self);
      self = 0;
      return 0;
    }
  }
  self->alloc = self;
  return self;
}

ALRUboolean
alru_init(alru_t *self, alru_uint64_t collisions, alru_uint64_t max) {
  if (0 == self) { return ALRU_FALSE; }
  if (0 == max) { return ALRU_FALSE; }
  memset(self, 0, sizeof(alru_t));
  if (0 == collisions) { collisions = DEFAULT_COLLISIONS; }
  self->collisions = factorof2(collisions);
  self->buckets = factorof(max, self->collisions) / self->collisions;
  while (self->buckets > BUCKET_MAX) {
    self->buckets = self->buckets >> 1;
    self->collisions = self->collisions << 1;
  }
  self->size = self->buckets * self->collisions;
  self->cache = malloc(self->size * sizeof(alru_uint64_t));
  return ALRU_TRUE;
}

ALRUboolean
alru_deinit(alru_t *self) {
  if (0 == self) { return ALRU_FALSE; }
  if (self->cache) { free(self->cache); }
  memset(self, 0, sizeof(alru_t));
  return ALRU_TRUE;
}

ALRUboolean
alru_set(alru_t *self, alru_uint64_t index, alru_uintptr_t value) {
  if (0 == self) { return ALRU_FALSE; }
  if (0 == value) { return ALRU_FALSE; }
  return ALRU_TRUE;
}

alru_uintptr_t
alru_get(alru_t *self, alru_uint64_t index) {
  if (0 == self) { return 0; }
  return 0;
}

ALRUboolean
alru_clear(alru_t *self) {
  if (0 == self) { return ALRU_FALSE; }
  return ALRU_TRUE;
}

static alru_uint64_t
factorof(alru_uint64_t n, alru_uint64_t factor) {
  n = factorof2(n);
  while (n & (factor - 1)) { n = n << 1; }
  return n;
}

static alru_uint64_t
factorof2(alru_uint64_t n) {
  alru_uint64_t p = 1;
  if (n && 0 == (n & (n - 1))) { return n; }
  while (p < n) { p = p << 1; }
  return p;
}
