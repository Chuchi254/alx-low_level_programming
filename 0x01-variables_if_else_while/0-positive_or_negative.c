#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - program that assigns a random number to the variable n
 * Return: 0 on success
 */
int main(void)
{
int n;
srand(time(0));
n = rand() - RAND_MAX / 2;
printf("%d is ", n);
if (n > 0)
{
	printf("positive\n");
}
else if (n == 0)
{
	printf("zero\n");
}
else
{
	printf("engative\n");
}
return (0);
}
