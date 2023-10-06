#include "main.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - This reads a text file and prints it to the POSIX std output
 * @filename: This is the name of the file to read
 * @letters: The numba of letters that should read and printed
 *
 * Return: This is the actual number of letters read and printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t descR, descW;
	char *buffer;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}
	descR = read(fd, buffer, letters);
	close(fd);
	if (descR == -1)
	{
		free(buffer);
		return (0);
	}
	descW = write(STDOUT_FILENO, buffer, descR);
	free(buffer);
	if (descR != descW)
		return (0);
	return (descW);
}
