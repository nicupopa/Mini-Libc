// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

// Source: https://elixir.bootlin.com/musl/latest/source/src/malloc/mallocng/malloc.c#L299

void *malloc(size_t size)
{
    void *map = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (map == MAP_FAILED)
	{
    	return NULL;
	}

	int ret = mem_list_add(map, size);

	if (ret < 0)
		return NULL;

    return map;
}

void *calloc(size_t nmemb, size_t size)
{
	void* ret = malloc(nmemb * size);

	return ret;
}

void free(void *ptr)
{
	struct mem_list * item;

	item = mem_list_find(ptr);

	if (item == NULL) {
		return;
	}

	munmap(item -> start, item -> len);
	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	struct mem_list * item;

	item = mem_list_find(ptr);

	void * ret = mremap(item -> start, item -> len, size, MREMAP_MAYMOVE);

	item -> len = size;
	item -> start = ret;

	return ret;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return realloc(ptr, size * nmemb);
}
