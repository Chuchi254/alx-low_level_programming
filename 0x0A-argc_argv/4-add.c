#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - prints the sum of integer arguments
 * @argc: argument count
 * @argv: vector to argument count
 * Return: return 0 on success
 * on failure, return 1 and set errno appropriately
 */
int main(int argc, char **argv)
{
	int i, j, sum = 0;
	char *str;

	if (argc == 1)
	{
		printf("%d\n", sum);
		return (0);
	}
	if (argc >= 2)
	{
		for (i  = 1; i < argc; i++)
		{
			str = malloc(sizeof(argv[i]));
				if (str == NULL)
				{
					printf("Error\n");
					free(str);
					return (1);
				}
			strcpy(str, argv[i]);

			for (j = 0; str[j] != '\0'; j++)
			{
				str[j] = argv[i][j];
				if (!isdigit(str[j]))
				{
					printf("Error\n");
					exit(EXIT_FAILURE);
				}
			}
			sum += atoi(argv[i]);
			free(str);
		}
		printf("%d\n", sum);
	}
	exit(EXIT_SUCCESS);
}
