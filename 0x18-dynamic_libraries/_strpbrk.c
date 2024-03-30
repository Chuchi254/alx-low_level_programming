#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to be scanned
 * @accept: string containing characters to match
 * Return: pointer to the character in s that matches one of
 * the characters in accept, NULL if no such character is found
 */

char *_strpbrk(char *s, char *accept)
{
	int count;

	if (s == NULL || accept == NULL)
		return (NULL);
	while (*s != '\0')
	{
		for (count = 0; accept[count] != '\0'; count++)
		{
			if (*s == accept[count])
				return (s);
		}
		s++;
	}
	return (NULL);
}
