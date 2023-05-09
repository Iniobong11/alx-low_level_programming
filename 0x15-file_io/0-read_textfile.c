#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads the text file, then print to POSIX stdout.
 * @filename: file pointer to the name being read.
 * @letters: number function of letters to be read and printed
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - actual number of bytes the function can read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t a, b, c;
	char *alarm;

	if (filename == NULL)
		return (0);

	alarm = malloc(sizeof(char) * letters);
	if (alarm == NULL)
		return (0);

	a = open(filename, O_RDONLY);
	b = read(a, alarm, letters);
	c = write(STDOUT_FILENO, alarm, b);

	if (a == -1 || b == -1 || c == -1 || c != b)
	{
		free(alarm);
		return (0);
	}

	free(alarm);
	close(a);

	return (c);
}
