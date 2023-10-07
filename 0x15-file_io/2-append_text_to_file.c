#include "main.h"

/**
 * append_text_to_file - this appends a text to what already exsts.
 * @filename: this is the filename.
 * @text_content: this is the added content.
 *
 * Return: 1 if the file exists. -1 if the file don't exist
 * or fail.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int nletas;
	int fdW;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (nletas = 0; text_content[nletas]; nletas++)
			;

		fdW = write(fd, text_content, nletas);

		if (fdW == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
