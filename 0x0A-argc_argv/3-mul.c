#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints product of 2 integers
 * @argc: argument count
 * @argv: vector to argument count
 * Return: return 0 on success
 * on failure, return -1 and set errno appropriately
 */

int main(int argc, char **argv)
{
	if (argc > 0 && argc == 3)
	{
		printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
