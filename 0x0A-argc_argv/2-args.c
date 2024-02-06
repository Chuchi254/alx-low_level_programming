#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints all arguments it receives followed by a new line
 * @argc: argument count
 * @argv: vector to argument count
 * Return: return 0 on Success
 * on failure, return -1 and set errno appropriately
 */

int main(int argc, char **argv)
{
	if (argc > 0)
	{
		int i;

		for (i = 0; i < argc; i++)
		{
			printf("%s\n", argv[i]);
		}
	}
	exit(EXIT_SUCCESS);
}
