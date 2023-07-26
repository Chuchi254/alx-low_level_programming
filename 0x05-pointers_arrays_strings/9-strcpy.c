#include "main.h"

/**
 * _strcpy - copies the string pointed by src including the null value
 * @src: source string to be copied
 * @dest: destination for string
 * Return: pointer to the destination string
 */

char *_strcpy(char *dest, char *src)
{
	*char original_dest;

	original_dest = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}
