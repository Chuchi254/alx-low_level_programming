#include "main.h"

/**
 * _strstr - finds substring from main string
 * @haystack: string be searched from
 * @needle: string been searched
 * Return: pointer to the first occurrence of the string been searched
 */

char *_strstr(char *haystack, char *needle)
{
	char *s;

	if (haystack == NULL || needle == NULL)
		return (NULL);
	while (*haystack != '\0')
	{
		s = _strchr(haystack, needle[0]);
		if (s == NULL)
			return (NULL);
		if (_strcmp(s, needle) == 0)
			return (s);
		haystack = s + 1;
	}
	return (NULL);
}
