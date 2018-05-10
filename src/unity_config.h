/**
* @file        UnityConfig.h
* @section    Define Unity output macros so they'll print using the 
*            SerialLog module from RuntimeLib
*/

// EDK-II
#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>

// IntelHeaders
#include <ntdatatypes.h>

#ifndef __UNITY_CONFIG_H__
#define __UNITY_CONFIG_H__

// Exclude all standard libraries
#define UNITY_EXCLUDE_SETJMP_H
#define UNITY_EXCLUDE_MATH_H
#define UNITY_EXCLUDE_STDINT_H
#define UNITY_EXCLUDE_LIMITS_H

// Define platform specific malloc/free functions (UEFI)
#define UNITY_EXCLUDE_STDLIB_MALLOC
#define UNITY_FIXTURE_MALLOC(size) AllocatePool(size)
#define UNITY_FIXTURE_FREE(ptr)    FreePool(ptr)

// Define variables width to fit 64bit (UEFI)
#define UNITY_SUPPORT_64
#define UNITY_INT_WIDTH 32
#define UNITY_LONG_WIDTH 64
#define UNITY_POINTER_WIDTH 64

// Define Unity output macros
#define UNITY_OUTPUT_CHAR(a)    (VOID)AsciiPrint("%c", (a))
#define UNITY_OUTPUT_FLUSH()
#define UNITY_OUTPUT_START()
#define UNITY_OUTPUT_COMPLETE()

#define UNITY_PRINT_EOL() \
    do \
    { \
        UNITY_OUTPUT_CHAR('\r'); \
        UNITY_OUTPUT_CHAR('\n'); \
    } while (0);

#endif /* __UNITY_CONFIG_H__ */
