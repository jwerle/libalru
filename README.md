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
$ cd librara
$ ./configure
$ make
$ sudo make install
```

## API

TODO

## Example

TODO

## License

MIT
