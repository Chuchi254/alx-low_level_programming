#include "main.h"

/**
 * append_text_to_file - appends texts at the end of a file
 * @filename: pointer to file name
 * @text_content: string to add to end of the file
 *
 * Return: -1 on failure, else return 1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);
	o = open(filename, O_WRONLY | O_APPEND);
	if (text_content != NULL)
	{
		for (len = 0; text_content[len]; len++)
			;
	}

	if (len > 0)
	{
		w = write(o, text_content, len);
		if (w == -1)
		{
			close(o);
			return (-1);
		}
	}
	close(o);

	return (1);
}
