#include "main.h"
#include <stdlib.h>

/**
 * checkElf - check if is an ELF file or not
 * @e_ident: array of pointers to interpret the ELF file
 * Return: exit with 98 on faillure
 */
void checkElf(unsigned char *e_ident)
{
	int x;

	for (x = 0; x < 4; x++)
	{
		if (e_ident[x] != 127 && e_ident[x] != 'E' &&
				e_ident[x] != 'L' && e_ident[x] != 'F')
		{
			dprintf(STDERR_FILENO, "Error : This File is not an ELF file.\n");
			exit(98);
		}
	}
}

/**
 * printMagic - prints Magic column of an ELF file
 * @e_ident: array of pointers to interpret the ELF file
 */
void printMagic(unsigned char *e_ident)
{
	int x;

	printf("  Magic:   ");
	for (x = 0; x < EI_NIDENT - 1; x++)
	{
		printf("%02x ", e_ident[x]);
	}
	printf("%02x\n", e_ident[x]);
}

/**
 * printClass - prints class of ELF header
 * @e_ident: array of pointers to interpret the ELF file
 */
void printClass(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("None\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Unknown class\n");
	}
}

/**
 * printData - prints Data of ELF header
 * @e_ident: array of pointers to interpret the ELF file
 */
void printData(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("None\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}

}

/**
 * printVersion - prints version number of ELF header
 * @e_ident: array of pointers to interpret the ELF file
 */
void printVersion(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf("None\n");
			break;
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
	}
}

/**
 * printOsAbi - Prints the OS/ABI of ELF header
 * @e_ident: array of pointers to interpret the ELF file
 */
void printOsAbi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - VIRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - reeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("UNIX - ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("UNIX - Stand-alone\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * printAbiVersion - prints the version of ABI of ELF header
 * @e_ident: array of pointers to interpret the ELF file
 */
void printAbiVersion(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * printType - prints the ELF object file type
 * @e_ident: array of pointers to interpret the ELF file
 * @e_type: ELF object file type
 */
void printType(unsigned char *e_ident, unsigned int e_type)
{
	printf("  Type:                              ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	switch (e_type)
	{
		case ET_NONE:
			printf("None\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown %u>\n", e_type);
			break;
	}
}

/**
 * printAddress - prints the Entry point of ELF address
 * @e_ident: array of bytes specifies how to interpret the file
 * @e_entry: ELF entry point virtual address
 */
void printAddress(unsigned char *e_ident, unsigned long int e_entry)
{
	printf("  Entry point address:               ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * closeElf - close file descriptor & free Buffer
 * @fd: ELF file descriptor
 * @Header: the header buffer
 */
void closeElf(int fd, Elf64_Ehdr *Header)
{
	free(Header);
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error : Can't close file descriptor %d\n", fd);
		exit(98);
	}
}


/**
 * main - shows the start info in the ELF header and file
 * @argc: number of arguments
 * @argv: array of argument pointers
 * Return: 0 on Successful
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr *elfHeader;
	ssize_t readChars = 0;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	elfHeader = malloc(sizeof(Elf64_Ehdr));
	if (!elfHeader)
	{
		dprintf(STDERR_FILENO, "Error : Not Enough Space\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error : Can't open file %s\n", argv[1]);
		exit(98);
	}
	readChars = read(fd, elfHeader, sizeof(Elf64_Ehdr));
	if (readChars < 0)
	{
		dprintf(STDERR_FILENO, "Error : Can't read file %s\n", argv[1]);
		closeElf(fd, elfHeader);
		exit(98);
	}
	checkElf(elfHeader->e_ident);
	printf("ELF Header:\n");
	printMagic(elfHeader->e_ident);
	printClass(elfHeader->e_ident);
	printData(elfHeader->e_ident);
	printVersion(elfHeader->e_ident);
	printOsAbi(elfHeader->e_ident);
	printAbiVersion(elfHeader->e_ident);
	printType(elfHeader->e_ident, elfHeader->e_type);
	printAddress(elfHeader->e_ident, elfHeader->e_entry);
	closeElf(fd, elfHeader);
	return (0);
}
