#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to be scanned
 * @accept: string containing the characters to be matched
 * Return: number of characters in the initial segment of s,
 * which consist of only of characters from accept, 0 otherwise
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int found, i;

	if(s == NULL || accept == NULL)
		return(0);
	while(*s != '\0')
	{
		found = 0;
		for(i = 0; accept[i] != '\0'; i++)
		{
			if(*s == accept[i])
			{
				found = 1;
				break;
			}
		}
		if(found == 0)
			break;
		count++;
		s++;
	}
	return(count);
}

