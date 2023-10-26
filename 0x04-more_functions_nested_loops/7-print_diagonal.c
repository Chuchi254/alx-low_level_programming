#include "main.h"

/**
 * print_diagonal - prints a line using underscores
 *
 * @n: number of hyphens to be used
 *
 */

void print_diagonal(int n)
{
        int count;

        if (n <= 0)
        {
                _putchar('\n');
        }
        else
        {
                for (count = 0; count < n; count++)
                {
                        _putchar('\\');
                }
                _putchar('\n');
        }
}
