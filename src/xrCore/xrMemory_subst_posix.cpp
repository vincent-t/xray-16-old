#include "stdafx.h"

MEMPOOL mem_pools[mem_pools_count];

void* xrMemory::mem_alloc(size_t size)
{
    if (0 == size) size = 1;
    void* data = malloc(size);
    if (!data)
      xrDebug::Fatal(DEBUG_INFO, "Out of memory. Memory request: %d K", size / 1024);

    return data;
}

void xrMemory::mem_free(void* P)
{
    free(P);
}

void* xrMemory::mem_realloc(void* P, size_t size)
{
    void* data = realloc(P, size);
    if (size && (0 == data))
      xrDebug::Fatal(DEBUG_INFO, "Out of memory. Memory request: %d K", size / 1024);
    return data;
}
