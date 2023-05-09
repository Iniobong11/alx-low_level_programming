#include "main.h"
#include "main.h"

/**
 * _strlen - finds the string length
 * @str: string pointer to the name of the file
 *
 * Return: length of the string
 */
size_t _strlen(char *str)
{
	size_t y;

	for (y = 0; str[y]; y++)
		;
	return (y);
}

/**
 * append_text_to_file - appends a word at the end of a file.
 * @filename: pointer name of the file
 * @text_content: End NULL string to added at the file's end
 *
 * Return: 1 successful and -1 failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int ini;
	ssize_t dur;

	if (filename == NULL)
		return (-1);
	ini = open(filename, O_WRONLY | O_APPEND);
	if (ini == -1)
		return (-1);
	if (text_content != NULL)
		dur = write(ini, text_content, _strlen(text_content));
	close(ini);
	if (dur == -1)
		return (-1);
	return (1);
}
