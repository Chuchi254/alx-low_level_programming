#include "main.h"

/** 
 *_strcpy - copies the stirng pointed to by src including the 
 *           the terminating null byte '\0'
 *
 * @src: oints to the string
 * @dest: pointed buffer
 */

char *_strcpy(char *dest, char *src)
{	
	char *original_dest;
	
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
