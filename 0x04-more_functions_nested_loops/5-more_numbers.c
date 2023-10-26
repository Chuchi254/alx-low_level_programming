#include "main.h"

/**
 * more_numbers - prints the number 0 to 14 followed by a new line
 */

void more_numbers(void)
{
	int count, i;
	char num = '0';

	for (i = 0; i < 10; i++)
	{
		for (count = 0; count <= 14; count++)
		{
			if (count >= 10)
			{
				_putchar('1');
				num = (count % 10) + '0';
			}
			else
			{
				num = count + '0';
			}
			_putchar(num);
		}
		_putchar('\n');
	}
}
