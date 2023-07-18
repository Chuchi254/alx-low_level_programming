#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - prints the last digit of the random variable stored in the value n
 * Return: 0 on success
 */
int main(void)
{
	int n;
	srand(time(0));
	n = rand() - RAND_MAX / 2;
	printf("Last digit of %d is ", n);
	int lastDigit = abs(n) % 10;
	if (lastDigit > 5)
	{
		printf("%d is greater than 5\n", lastDigit);
	}
	else if (lastDigit == 0)
	{
		printf("0\n");
	}
	else
	{
		printf("%d is less than 5\n", lastDigit);
	}
	return (0);
}
