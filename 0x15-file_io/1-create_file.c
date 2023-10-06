#include "main.h"

/**
 * create_file - this creates a file
 * @filename: the filename of file.
 * @text_content: the content writen in the file.
 *
 * Return: 1 if successful. -1 incase it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int nletas;
	int rwr;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nletas = 0; text_content[nletas]; nletas++)
		;

	rwr = write(fd, text_content, nletas);

	if (rwr == -1)
		return (-1);

	close(fd);

	return (1);
}
