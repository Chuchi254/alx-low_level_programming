#include "main.h"

/**
 * read_textfile - reads texts from files
 * @filename: points to string with the file name
 * @letters: refers to the memory size of the file
 * Return: number of bytes read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytesRead, bytesWritten;
	char *buffer;

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		perror("open failed");
		exit(EXIT_FAILURE);
	}
	bytesRead = read(fd, buffer, letters);
	if (bytesRead == -1)
	{
		free(buffer);
		close(fd);
		perror("read failed");
		exit(EXIT_FAILURE);
	}
	bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
	if (bytesWritten == -1)
	{
		free(buffer);
		close(fd);
		perror("write failed");
		exit(EXIT_FAILURE);
	}
	close(fd);
	free(buffer);
	return (bytesRead);
}
