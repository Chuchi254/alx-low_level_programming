#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - returns the minimum number of coins to make change
 * @argc: argument count
 * @argv: vector to argument count
 * Return: 0 on success
 * else, return -1 and set errno appropriately
 */

int main(int argc, char **argv)
{
	int arr[] = {25, 10, 5, 2, 1};
	int num = atoi(argv[1]);
	int i, count = 0;

	if (argc < 2 || argc > 2)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (num < 0)
	{
		num = 0;
		printf("%d", num);
		exit(EXIT_SUCCESS);
	}

	for (i = 0; i < 5; i++)
	{
		while (num >= arr[i])
		{
			num -= arr[i];
			count++;
		}
		if (num == 0)
			break;
	}
	printf("%d\n", count);
	exit(EXIT_SUCCESS);
}
