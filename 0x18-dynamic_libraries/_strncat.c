#include "main.h"

/**
 * _strncat - concatenates two string
 * @dest: string to be added to
 * @src: string to be added
 * @n: size of string to be added
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int count;
	int len = _strlen(dest);

	if (src == NULL)
		return (NULL);
	for (count = 0; count < n && src[count] != '\0'; count++)
	{
		dest[len + count] = src[count];
	}
	dest[len + count] = '\0';
	return (dest);
}
