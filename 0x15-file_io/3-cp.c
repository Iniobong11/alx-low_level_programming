#include "main.h"
#include <stdlib.h>
#define BUFF_SIZE 1024

/**
 * main - copies the content of a file to a new file
 * @argc: number of arguments passed
 * @argv: an array of pointers arguments
 * Return: 0 (Successful)
 */
int main(int argc, char **argv)
{
	int fd_start, fd_end;
	char buff[BUFF_SIZE];
	ssize_t readChars = 0;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_start file_end\n");
		exit(97);
	}
	fd_start = open(argv[1], O_RDONLY);
	if (fd_start < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_end = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 00664);
	while ((readChars = read(fd_start, buff, BUFF_SIZE)) > 0)
	{
		if (fd_end < 0 || write(fd_end, buff, readChars) < 0)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (readChars < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (close(fd_start) == -1 || close(fd_end) == -1)
	{
		if (close(fd_start) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_start);
		if (close(fd_end) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_end);
		exit(100);
	}
	return (0);
}
