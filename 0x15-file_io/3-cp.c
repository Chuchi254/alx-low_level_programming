#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/**
 * print_error_and_exit - Prints error message and exits with a specific code
 * @exit_code: The exit code to use
 * @message: The error message format string
 * @file: The file name or file descriptor to inlcude in the error message
 */
void print_error_and_exit(int exit_code, const char *message, const char *file)
{
	dprintf(STDERR_FILENO, message, file);
	exit(exit_code);
}

/**
 * open_file - Opens a file and returns the file descriptor
 * @filename: The name of the file to open
 * @flags: The flags to use for opening the file
 * @mode: The mode to use for creating the file (if applicable)
 *
 * Return: The file descriptor on success, or exit with the appropriate error
 * on failure
 */
int open_file(const char *filename, int flags, mode_t mode)
{
	int fd = open(filename, flags, mode);

	if (fd == -1)
	{
		if (flags & O_CREAT)
			print_error_and_exit(99, "Error: CAn't write to %s\n", filename);
		else
			print_error_and_exit(98, "Error: Can't read from file %s\n", filename);
	}

	return (fd);
}

/**
 * close_file - Closes a file descriptor and checks for errors
 * @fd: The file descriptor to close
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_content - Copies the content from one file to another
 * @fd_from: The file descriptor of the source file
 * @fd_to: The file descriptor of the destination file
 */
void copy_content(int fd_from, int fd_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close_file(fd_from);
			close_file(fd_to);
			print_error_and_exit(99, "Error: Can't write to %s\n", buffer);
		}
	}

	if (bytes_read == -1)
	{
		close_file(fd_from);
		close_file(fd_to);
		print_error_and_exit(98, "Error: Can't read from file %s\n", buffer);
	}
}

/**
 * main - Entry point for the cp program
 * @argc: The number of arguments
 * @argv: The array of arguments
 *
 * Return: 0 on success, lr one of the specified error codes on failure
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_file(argv[1], O_RDONLY, 0);
	fd_to = open_file(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	copy_content(fd_from, fd_to);

	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
