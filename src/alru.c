#include <alru/alru.h>
#include <string.h>
#include "crc16.h"

ALRUboolean
alru_init(alru_t *alru, const alru_uint64_t max) {
  if (0 == alru) { return ALRU_FALSE; }
  if (0 == max) { return ALRU_FALSE; }
  memset(alru, 0, sizeof(alru_t));
  return ALRU_TRUE;
}

ALRUboolean
alru_set(alru_t *alru, const alru_uint64_t index, const alru_uintptr_t value) {
  if (0 == alru) { return ALRU_FALSE; }
  if (0 == value) { return ALRU_FALSE; }
  return ALRU_TRUE;
}

alru_uintptr_t
alru_get(alru_t *alru, const alru_uint64_t index) {
  if (0 == alru) { return 0; }
  return 0;
}

ALRUboolean
alru_clear(alru_t *alru) {
  if (0 == alru) { return ALRU_FALSE; }
  return ALRU_TRUE;
}
