#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: string searched from
 * @c: character been searched
 * Return: pointer to the first occurrence of the character c in s,
 * otherwise NULL
 */

char *_strchr(char *s, char c)
{
	int count;

	if (s == NULL)
		return (NULL);
	while (s[count] != '\0')
	{
		if (s[count] == c)
			return (&s[count]);
		count++;
	}
	return (NULL);
}
