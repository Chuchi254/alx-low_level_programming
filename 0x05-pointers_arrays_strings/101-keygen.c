#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

char* generate_password()
{
	static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char* password = (char*)malloc((PASSWORD_LENGTH + 1) * sizeof(char));

	if (password == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	int i, index;

	for (i = 0; i < PASSWORD_LENGTH; i++)
	{
		index = rand() % (sizeof(charset) - 1);
		password[i] = charset[index];
	}
	password[PASSWORD_LENGTH] = '\0';

	return (password);
}

/**
 * main -generates random password
 * Return: 0 
 */

int main()
{
	srand(time(0));

	char* password = generate_password();
	printf("Generated password: %s\n", password);

	free(password);
	return (0);
}
