#ifndef ALRU_COMMON_H
#define ALRU_COMMON_H

/**
 * Much of this file has been inspired by `KHR/khrplatform.h` header file
 * provided by the hc Group
 */

#if defined(_WIN32)
#  define ALRU_EXPORT __declspec(dllimport)
#elif defined(__GNUC__) && (__GNUC__ * 100 + __GNUC_MINOR) >= 303
#  define ALRU_EXPORT __attribute__((visibility("default")))
#  define ALRU_INLINE inline
#else
#  define ALRU_EXPORT
#  define ALRU_INLINE
#endif

#ifndef ALRU_ALIGNMENT
#  define ALRU_ALIGNMENT sizeof(unsigned long) /* platform word */
#endif

typedef int ALRUint;
typedef int ALRUsizei;
typedef void ALRUvoid;
typedef char ALRUchar;
typedef long ALRUlong;
typedef short ALRUshort;

typedef unsigned int ALRUuint;
typedef unsigned int ALRUenum;
typedef unsigned char ALRUuchar;
typedef unsigned short ALRUushort;

typedef unsigned int ALRUbitfield;
typedef unsigned char ALRUboolean;

// C99
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__GNUC__)

#include <stdint.h>
typedef int32_t alru_int32_t;
typedef int64_t alru_int64_t;
typedef uint32_t alru_uint32_t;
typedef uint64_t alru_uint64_t;

#define ALRU_SUPPORT_INT64 1
#define ALRU_SUPPORT_FLOAT 1

#elif defined(_WIN32)

typedef __int32 alru_int32_t;
typedef __int64 alru_int64_t;
typedef unsigned __int32 alru_uint32_t;
typedef unsigned __int64 alru_uint64_t;

#define ALRU_SUPPORT_INT64 1
#define ALRU_SUPPORT_FLOAT 1

#else

#include <stdint.h>

typedef int32_t alru_int32_t;
typedef int64_t alru_int64_t;
typedef uint32_t alru_uint32_t;
typedef uint64_t alru_uint64_t;

#define ALRU_SUPPORT_INT64 1
#define ALRU_SUPPORT_FLOAT 1

#endif

typedef signed char alru_int8_t;
typedef unsigned char alru_uint8_t;
typedef signed short int alru_int16_t;
typedef unsigned short int alru_uint16_t;

#ifdef _WIN64
typedef signed long long int alru_intptr_t;
typedef signed long long int alru_ssize_t;
typedef unsigned long long int alru_uintptr_t;
typedef unsigned long long int alru_usize_t;
#else
typedef signed long int alru_intptr_t;
typedef signed long int alru_ssize_t;
typedef unsigned long int alru_uintptr_t;
typedef unsigned long int alru_usize_t;
#endif

#if ALRU_SUPPORT_FLOAT
typedef float alru_float_t;
#endif

#if ALRU_SUPPORT_INT64
typedef alru_uint64_t alru_utime_nanoseconds_t;
typedef alru_int64_t alru_stime_nanoseconds_t;
#endif

#ifndef ALRU_MAX_ENUM
#define ALRU_MAX_ENUM 0x7FFFFFFF
#endif

typedef enum {
  ALRU_FALSE = 0,
  ALRU_TRUE  = 1,
  ALRU_BOOLEAN_ENUM_FORCE_SIZE = ALRU_MAX_ENUM
} alru_boolean_enum_t;

/**
 * ALRU typedefs
 */

typedef alru_uint8_t ALRUubyte;
typedef alru_float_t ALRUfloat;
typedef alru_ssize_t ALRUsizeiptr;
typedef alru_intptr_t ALRUintptr;

typedef alru_int64_t ALRUint64;
typedef alru_uint64_t ALRUuint64;

#endif
