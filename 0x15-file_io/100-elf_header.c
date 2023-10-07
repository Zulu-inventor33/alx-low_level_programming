#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void scan_elf(unsigned char *e_ident);
void imprint_magic(unsigned char *e_ident);
void imprint_class(unsigned char *e_ident);
void imprint_data(unsigned char *e_ident);
void imprint_version(unsigned char *e_ident);
void imprint_abi(unsigned char *e_ident);
void imprint_osabi(unsigned char *e_ident);
void imprint_type(unsigned int e_type, unsigned char *e_ident);
void imprint_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * scan_elf - this scans if a file is an ELF file.
 * @e_ident: this is a pointer to an array with the ELF magic numbers.
 *
 * Description: Incase file is not an ELF file - exit code 98.
 */
void scan_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
			e_ident[index] != 'E' &&
			e_ident[index] != 'L' &&
			e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * imprint_magic - this Prints the magic numbers of an ELF header.
 * @e_ident: this is a pointer to an array containing the ELF magic numbers.
 *
 * Description: the agic numbers are separated by spaces.
 */
void imprint_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * imprint_class - this Prints the class of an ELF header.
 * @e_ident: this is a pointer to an array containing the ELF class.
 */
void imprint_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
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
 * imprint_data - this Prints the data of an ELF header.
 * @e_ident: this is a pointer to an array containing the ELF class.
 */
void imprint_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * imprint_version - this Prits the version of an ELF header.
 * @e_ident: this is a pointer to an array containing the ELF version.
 */
void imprint_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
		   e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * imprint_osabi - this Print the OS/ABI of an ELF header.
 * @e_ident: this is pointer to an array contaiing the ELF version.
 */
void imprint_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

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
		printf("UNIX - TRU64\n");
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
 * imprint_abi - this actually Prints the ABI version of an ELF header.
 * @e_ident: pointer to array containing the ELF ABI version.
 */
void imprint_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
		   e_ident[EI_ABIVERSION]);
}

/**
 * imprint_type - this Prints the type of an ELF header.
 * @e_type: a ELF type.
 * @e_ident: the pointer to an array containing the ELF class.
 */
void imprint_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

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
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * imprint_entry - this Prints the entry point of an ELF header.
 * @e_entry: address of the ELF entry point.
 * @e_ident: the pointer to an array containing the ELF class.
 */
void imprint_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - this Closes an ELF file.
 * @elf: this is the file descriptr of the ELF file.
 *
 * Description: If the file could be closd - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);

		exit(98);
	}
}

/**
 * main - The main will Display the information containd at
 *        ELF header at the start of an ELF file.
 * @argc: number of arguments supplied to the program.
 * @argv: array of pointers to arguments.
 *
 * Return: 0 on success.
 *
 * Description: If file ain't an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	scan_elf(header->e_ident);
	imprintf("ELF Header:\n");
	imprint_magic(header->e_ident);
	imprint_class(header->e_ident);
	imprint_data(header->e_ident);
	imprint_version(header->e_ident);
	imprint_osabi(header->e_ident);
	imprint_abi(header->e_ident);
	imprint_type(header->e_type, header->e_ident);
	imprint_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
