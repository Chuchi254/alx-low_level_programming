#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array, using malloc
 *
 * @nmemb: The number of elements
 * @size: The size of each element in bytes
 *
 * Return: A pointer to the allocated memory. The memory is set to 0.
 * if nmemb or size is 0, then _calloc returns NULL.
 * If malloc fails, then _calloc returns NULL.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		ptr[i] = 0;

	return (ptr);
}
