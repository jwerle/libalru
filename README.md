libalru
=======

## Abstract

`libalru` is a library for creating really fast numeric based LRU caches that
leverage an optimized [CRC-16-CCITT](
http://automationwiki.com/index.php/CRC-16-CCITT) ported from
[array-lru](https://github.com/mafintosh/array-lru). Values are unsigned
64 bit integers that point to a memory address and are associated with
an unsigned integer index where index is at most the size of the
internal cache.

## Installation

With [clib](https://github.com/clibs/clib) do:

```sh
$ clib install jwerle/libalru
```

Or from source do:

```sh
$ git clone git@github.com:jwerle/libalru.git
$ cd libalru
$ ./configure
$ make
$ sudo make install
```

## API

### `typedef struct alru alru_t;`

TODO

### `typedef ALRUvoid (alru_evict_f)(alru_t *, alru_uint64_t, alru_uintptr_t);`

TODO

### `ALRUboolean alru_init(alru_t *alru, const alru_uint64_t max);`

Initializes an already allocated `alru_t *` pointer with
a max cache size. If an already

### `ALRUboolean alru_set(alru_t *alru, const alru_uint64_t index, const alru_uintptr_t value);`

TODO

### `alru_uintptr_t alru_get(alru_t *alru, const alru_uint64_t index);`

TODO

### `ALRUboolean alru_clear(alru_t *alru);`

TODO

### `inline ALRU_EXPORT alru_t * alru(const alru_uint64_t max);`

Allocates and returns a new `alru_t *` pointer.

## Example

TODO

## License

MIT
