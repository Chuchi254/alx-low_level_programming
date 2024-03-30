#include "main.h"

/**
 * _strncpy - copies a string to buffer
 * @dest: copied string
 * @src: string to be copied
 * @n: size of string to be copied
 */

char *_strncpy(char *dest, char *src, int n)
{
	int count;

	if(src == NULL)
		return(NULL);
	for(count = 0; count < n && src[count] != '\0'; count++)
	{
		dest[count] = src[count];
	}
	dest[count] = '\0';
	return(dest);
}
