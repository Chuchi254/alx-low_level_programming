#include "main.h"

/**
 * _strcat - concatenates 2 strings
 * @dest: string to be added to
 * @src: string to be added
 * Return: dest
 */

char *_strcat(char *dest, char *src)
{
	int count = 0;
	int len;

	len = _strlen(dest);
	if (src == NULL)
		return (NULL);
	while (src[count] != '\0')
	{
		dest[len + count] = src[count];
		count++;
	}
	dest[len + count] = '\0';
	return (dest);
}
