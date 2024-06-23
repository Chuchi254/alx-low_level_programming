#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Prints error message to stderr and exits with code status 98
 * @message: The error message to print
 */
void print_error(const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(98);
}

/**
 * check_elf - Checks if a file is an ELF file
 * @e_ident: The identification bytes of the ELF header
 */
void check_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAG0] != ELFMAG0 ||
			e_ident[EI_MAG1] != ELFMAG1 ||
			e_ident[EI_MAG2] != ELFMAG2 ||
			e_ident[EI_MAG3] != ELFMAG3)
		print_error("Error: Not an ELF file");
}

/**
 * print_magic - Prints the magic numbers of the ELF header
 * @e_ident: The identification bytes of the ELF header
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf(" Magic:	");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%2.2x ", e_ident[i]);
	printf("\n");
}

/**
 * print_class - Prints the class of the ELF header
 * @e_ident: The identification bytes of the ELF header
 */
void print_class(unsigned char *e_ident)
{
	printf(" Class:	");
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
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - Prints the data encoding of the ELF header
 * @e_ident: The identification bytes of the ELF header
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data:	");
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
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

/**
 * print_version - Prints the version of thr ELF header
 * @e_ident: The identification bytes of the ELF header
 */
void print_version(unsigned char *e_ident)
{
	printf(" Version:	%d", e_ident[EI_VERSION]);
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
	printf(" OS/ABI:	");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
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
			printf("ARM\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abiversion - Prints the ABI version of the ELF header
 * @e_ident: The identification bytes of the ELF header
 */
void print_abiversion(unsigned char *e_ident)
{
	printf(" ABI Version:	%d\n", e_ident[EI_ABIVERSION]);
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
	printf(" Type:	");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file\n");
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
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point address of the ELF HEADER
 * @e_entry: The entry point address
 * @e_ident: The identification bytes of the ELF header
 */
void print_entry(uint64_t e_entry, unsigned char *e_ident)
{
	printf(" Entry point address:	");
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * main - Displays the information contained in the ELF header at the
 * start of an ELF file
 * @argc: The number of arguments
 * @argv: The array of arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	int fd;
	ssize_t bytes_read;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Can't read from file");

	bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1 || bytes_read != sizeof(Elf64_Ehdr))
	{
		close(fd);
		print_error("Error: Can't read from file");
	}

	printf("Elf Header:\n");
	check_elf(header.e_ident);
	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_abiversion(header.e_ident);
	print_type(header.e_type, header.e_ident);
	print_entry(header.e_entry, header.e_ident);

	close(fd);
	return (0);
}
