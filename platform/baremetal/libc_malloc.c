#include <stdlib.h>

#include <bmk/memalloc.h>
#include <bmk/string.h>

int
posix_memalign(void **rv, size_t nbytes, size_t align)
{
	void *v;
	int error = 10; /* XXX */

	if ((v = bmk_memalloc(nbytes, align)) != NULL) {
		*rv = v;
		error = 0;
	}

	return error;
}

void *
malloc(size_t size)
{

	return bmk_memalloc(size, 8);
}

void *
calloc(size_t n, size_t size)
{
	void *v;
	size_t tot = n * size;

	if ((v = malloc(tot)) != NULL) {
		bmk_memset(v, 0, tot);
	}

	return v;
}

void *
realloc(void *cp, size_t nbytes)
{

	return bmk_memrealloc(cp, nbytes);
}

void
free(void *cp)
{

	bmk_memfree(cp);
}
