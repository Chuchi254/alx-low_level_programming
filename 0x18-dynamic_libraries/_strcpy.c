#include "main.h"

/**
 * _strcpy - copies string to buffer
 * @src: string to be copied
 * @dest: copied string
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int count = 0;

	if (src == NULL)
		return (NULL);
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
