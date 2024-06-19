#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * is_digit - checks if a string contains only digits
 *
 * @str: the string to check
 *
 * Return: 1 if str contains only digits, 0 otherwise
 */
int is_digit(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * init_result_array - Initializes the result array
 *
 * @len1: Length of the first number
 * @len2: Length of the second number
 *
 * Return: A pointer to the initialized result array
 */
int *init_result_array(int len1, int len2)
{
	int *result, i;
	int size = len1 + len2;

	result = malloc(size * sizeof(int));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		result[i] = 0;

	return (result);
}

/**
 * multiply_strings - multiplies two string represented as strings
 *
 * @num1: the first number
 * @num2: the second number
 * @result: the result array to store multiplication result
 */
void multiply_strings(char *num1, char *num2, int *result)
{
	int len1 = 0, len2 = 0, i, j, carry, n1, n2, sum;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}
		result[i + j + 1] += carry;
	}
}

/**
 * multiply - Multiplies two numbers represented as strings
 *
 * @num1: The first number
 * @num2: The second number
 *
 * Return: A pointer to the result of the multiplicaton
 */
char *multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, k, *result;
	char *final_result;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	result = init_result_array(len1, len2);
	if (result == NULL)
		return (NULL);

	multiply_strings(num1, num2, result);

	final_result = malloc(len1 + len2 + 1);
	if (final_result == NULL)
	{
		free(result);
		return (NULL);
	}

	k = 0;
	for (i = 0; i < len1 + len2; i++)
	{
		if (!(k == 0 && result[i] == 0))
			final_result[k++] = result[i] + '0';
	}
	final_result[k] = '\0';

	free(result);

	if (k == 0)
	{
		final_result[0] = '0';
		final_result[1] = '\0';
	}
	return (final_result);
}

/**
 * main - multiplies two positive numbers
 *
 * @argc: the number of arguments
 * @argv: the argument
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;
	int i;

	if (argc != 3)
		return (98);

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit(num1) || !is_digit(num2))
		return (98);

	result = multiply(num1, num2);
	if (result == NULL)
		return (98);

	for (i = 0; result[i] != '\0'; i++)
		putchar(result[i]);
	_putchar('\n');

	free(result);
	return (0);
}
