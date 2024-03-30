#include "main.h"

/**
 * _strlen - returns length of string
 * @s: string to be checked
 * Return: length of s on success, else 0
 */

int _strlen(char *s)
{
	int count = 0;

	if(s == NULL)
		return(0);
	while(s[count] != '\0')
		count++;
	return(count);
}
