#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <elf.h>

void print_error_and_exit(const char *msg) {
    dprintf(STDERR_FILENO, "%s\n", msg);
    exit(98);
}

void check_elf_header(const unsigned char *e_ident) {
    if (e_ident[EI_MAG0] != ELFMAG0 ||
        e_ident[EI_MAG1] != ELFMAG1 ||
        e_ident[EI_MAG2] != ELFMAG2 ||
        e_ident[EI_MAG3] != ELFMAG3) {
        print_error_and_exit("Error: Not an ELF file");
    }
}

void print_elf_header(const Elf32_Ehdr *header) {
    int i;

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS]) {
        case ELFCLASSNONE: printf("none\n"); break;
        case ELFCLASS32:   printf("ELF32\n"); break;
        case ELFCLASS64:   printf("ELF64\n"); break;
        default:           printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
    }

    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA]) {
        case ELFDATANONE: printf("none\n"); break;
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default:          printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
    }

    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_NONE:       printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX:       printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD:     printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX:      printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS:    printf("UNIX - Solaris\n"); break;
        case ELFOSABI_IRIX:       printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD:    printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64:      printf("UNIX - TRU64\n"); break;
        case ELFOSABI_ARM:        printf("ARM\n"); break;
        case ELFOSABI_STANDALONE: printf("Standalone App\n"); break;
        default:                  printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
    }

    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (header->e_type) {
        case ET_NONE: printf("NONE (None)\n"); break;
        case ET_REL:  printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN:  printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default:      printf("<unknown: %x>\n", header->e_type);
    }

    printf("  Entry point address:               0x%x\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    int fd;
    ssize_t read_bytes;
    Elf32_Ehdr header;

    if (argc != 2) {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
        exit(98);
    }

    read_bytes = read(fd, &header, sizeof(header));
    if (read_bytes != sizeof(header)) {
        close(fd);
        print_error_and_exit("Error: Can't read ELF header");
    }

    check_elf_header(header.e_ident);
    print_elf_header(&header);

    if (close(fd) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(98);
    }

    return 0;
}

