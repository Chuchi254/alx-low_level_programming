#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the name of the program
 * @argc - the number of arguments
 * @argv - the array of arguments in form of strings
 * REturn: Return 0 on succcess
 * on error, return -1 and set errno appropriately
 */

int main(int argc, char **argv)
{
	if (argc > 0)
		printf("%s\n", argv[0]);
	exit(EXIT_SUCCESS);
}
