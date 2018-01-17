#ifndef ALRU_CRC16_H
#define ALRU_CRC16_H

#include <alru/common.h>

/**
 * 16bit cyclic redundancy check that implements the
 * "CRC-16-CCITT" error detection algorithm using the
 * `y = x16 + x12 + x5 + 1' polynomial optimized for numerical
 * values.
 *
 * @see {https://github.com/mafintosh/array-lru/blob/master/crc16.js}
 * @see {https://en.wikipedia.org/wiki/Cyclic_redundancy_check}
 * @see {http://automationwiki.com/index.php/CRC-16-CCITT}
 *
 * @param {uint16_t} n The 16 bit numeric value to perform a CRC-16 check on
 * @return {uint16_t}
 */
alru_uint16_t
crc16(alru_uint16_t n);

#endif
