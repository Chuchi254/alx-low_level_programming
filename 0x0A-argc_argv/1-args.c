#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the number of arguments in the program
 * @argc: number of arguments
 * @argv: vector to arguments
 * Return: returns 0 on sucess
 * on failure, return -1 and set errno appropriately
 */
int main(int argc, char **argv)
{
	if (argc > 0)
	{
		printf("%d\n", argc - 1);
		(void)argv;
	}
	exit(EXIT_SUCCESS);
}
