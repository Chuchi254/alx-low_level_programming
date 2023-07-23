#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - checks whether a number is positive or negative
 *
 * Return: 0 on success
 */

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (n > 0)
	{
		puts("%d is positive\n", n);
	}
	else if (n == 0)
	{
		puts("%d is zero\n", n);
	}
	else
	{
		puts("%d is negative\n", n);
	}
	return (0);
}
