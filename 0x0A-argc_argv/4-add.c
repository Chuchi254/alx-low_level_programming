#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the sum of integer arguments
 * @argc: argument count
 * @argv: vector to argument count
 * Return: return 0 on success
 * on failure, return 1 and set errno appropriately
 */
int main(int argc, char **argv)
{
	if (argc > 0)
	{
		int i, sum = 0;

		for (i = 1; i < argc; i++)
		{
			int num = atoi(argv[i]);

			if (num == 0)
			{
				printf("Error\n");
				exit(EXIT_FAILURE);
			}
			else
				sum = sum + num;
		}
		printf("%d\n", sum);
	}
	exit(EXIT_SUCCESS);
}
