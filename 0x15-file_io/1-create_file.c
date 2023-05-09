#include "main.h"
/**
 * create_file -creates an array of new file
 *
 * @text_content: NULL pointer string to write to the file
 * @filename: pointer name of the created file
 *
 * Return: 1 successful, -1 failure
 */
int create_file(const char *filename, char *text_content)
{
	int x, y, dur = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (dur = 0; text_content[dur];)
			dur++;
	}

	x = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	y = write(x, text_content, dur);

	if (x == -1 || y == -1)
		return (-1);

	close(x);

	return (1);
}
