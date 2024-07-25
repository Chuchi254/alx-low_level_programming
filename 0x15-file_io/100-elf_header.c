#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

/**
 * print_error_and_exit - prints error and exits code
 * @msg: message to be printed
 */

void print_error_and_exit(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

/**
 * print_elf_header_info - prints elf header information
 * @header: header to printed
 */

void print_elf_header_info(Elf64_Ehdr *header)
{
	int i;

	printf("Magic:   ");
	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("Class:                             ");
	switch (header->e_ident[EI_CLASS])
}

/**
 * print_class - Prints the class of the ELF header
 * @e_ident: The identification bytes of the ELF header
 */
void print_class(unsigned char *e_ident)
{
	printf("Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("NONE\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
	}

	printf("Data:                              ");
	switch (header->e_ident[EI_DATA])
}

/**
 * print_data - Prints the data encoding of the ELF header
 * @e_ident: The identification bytes of the ELF header
 */
void print_data(unsigned char *e_ident)
{
	printf("Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("NONE\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
	}

	printf("Version:                           %d (current)\n",
			header->e_ident[EI_VERSION]);
	printf("OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
}

/**
 * print_version - Prints the version of thr ELF header
 * @e_ident: The identification bytes of the ELF header
 */
void print_version(unsigned char *e_ident)
{
	printf("Version:			   %d", e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
	}
}

/**
 * print_osabi - Prints the OS/ABI of the ELF header
 * @e_ident: The identification bytes of the ELF header
 */
void print_osabi(unsigned char *e_ident)
{
	printf("OS/ABI:                            ");
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
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
	}
	printf("ABI Version:                       %d\n",
		header->e_ident[EI_ABIVERSION]);
	printf("Type:                              ");
	switch (header->e_type)
}

/**
 * print_abiversion - Prints the ABI version of the ELF header
 * @e_ident: The identification bytes of the ELF header
 */
void print_abiversion(unsigned char *e_ident)
{
	printf("ABI Version:			   %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of the ELF header
 * @e_type: The type of the ELF file
 * @e_ident: The identification bytes of the ELF header
 */
void print_type(uint16_t e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type = e_type >> 8;
	printf("Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
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
			printf("<unknown: %x>\n", header->e_type);
	}
	printf("Entry point address:               0x%lx\n",
			(unsigned long) header->e_entry);
}

/**
 * print_entry - Prints the entry point address of the ELF HEADER
 * @e_entry: The entry point address
 * @e_ident: The identification bytes of the ELF header
 */
void print_entry(uint64_t e_entry, unsigned char *e_ident)
{
	printf(" Entry point address:              ");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * main - entry point
 * @argc: arguments
 * @argv: argument count
 *
 * Return: 0 Always
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		print_error_and_exit("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error_and_exit(strerror(errno));

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		close(fd);
		print_error_and_exit("Failed to read ELF header");
	}

	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		close(fd);
		print_error_and_exit("Not an ELF file");
	}

	print_elf_header_info(&header);

	if (close(fd) == -1)
		print_error_and_exit("Failed to close file");

	return (0);
}
