#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - prints an error message to stderr and exits with a given code
 * @code: the exit code
 * @message: the error message format string
 * @param: additional parameter for the error message
 */

void error_exit(int code, const char *message, const char *param)
{
	dprintf(STDERR_FILENO, message, param);
	exit(code);
}

/**
 * main - copies the content of one file to another
 * @argc: the number of arguments
 * @argv: the array of arguments
 *
 * Return: 0 on success, or exits with a specific code on error
 */

int main(int argc, char **argv)
{
	int file_from, file_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;
	char fd_str[12];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n", NULL);

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	if (file_to == -1)
		error_exit(99, "Error: Can't write to %s\n", argv[2]);

	while ((bytes_read = read(file_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
			error_exit(99, "Error: Can't write to %s\n", argv[2]);
	}

	if (bytes_read == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	if (close(file_from) == -1)
	{
		sprintf(fd_str, "%d", file_from);
		error_exit(100, "Error: Can't close fd %d\n", fd_str);
	}

	if (close(file_to) == -1)
	{
		sprintf(fd_str, "%d", file_to);
		error_exit(100, "Error: Can't close fd %d\n", fd_str);
	}

	return (0);
}
