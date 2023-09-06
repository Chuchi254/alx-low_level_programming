#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads text files and prints to STDOUT
 * @filename: text file to be read
 * @letters: number of letters read
 *
 * Return: actual number of bytes that are read and printed (byteNumber)
 * 0 is returned when filename is NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t byteNumber, fileDescriptor, t;
	char *BUF;

	fileDescriptor = open(filename, O_RDONLY);
	if (fileDescriptor == -1)
		return (0);
	BUF = malloc(sizeof(char) * letters);
	t = read(fileDescriptor, BUF, letters);
	byteNumber = write(STDOUT_FILENO, BUF, t);

	free(BUF);
	close(fileDescriptor);
	return (byteNumber);
}
