#pragma once

#include <types.h>

void *malloc(size_t size);

void free(void *p);

void *zalloc(size_t);

void *dma_alloc_coherent(size_t size, unsigned long *pa);

struct list_head *get_heap_head_list(void);

#define SAFE_FREE(p) \
	do {  \
		free(p); \
		p = NULL; \
	} while (0)

#define kmalloc(s, f) malloc(s)
#define kfree(p) free(p)

#define vmalloc(s) malloc(s)
#define vfree(p) free(p)
