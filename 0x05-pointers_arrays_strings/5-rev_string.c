#include "main.h"

/**
 * rev_string - reverses a string
 *
 * @s: stores the string
 */

void rev_string(char *s)
{
	int length = 0;
	char *end = s;
	char temp;

	while (*end != '\0')
	{
		length++;
		end++;
	}
	end--;

	while (s < end)
	{
		temp = *s;
		*s = *end;
		*end = temp;

		s++;
		end--;
	}
}
