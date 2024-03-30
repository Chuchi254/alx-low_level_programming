#include "main.h"

/**
 * _atoi - converts a string to digit
 * @s: string pointed to
 * Return: digit of converted string
 */

int _atoi(char *s)
{
	int count = 0;
	int sign = 1;
	int result = 0;

	if(s == NULL)
		return(0);
	if(s[count] == ' ')
		count++;
	if(s[count] == '-')
	{
		sign = -1;
		count++;
	}
	if(s[count] == '+')
		count++;
	while(s[count] != '\0' && s[count] >= '0' && s[count] <= '9')
	{
		result = (result * 10) + (s[count] - '0');
		count++;
	}
	return(result * sign);
}	
