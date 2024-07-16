#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/types.h>

// ELF Header structure
typedef struct {
    unsigned char e_ident[16]; // ELF Identification bytes
    uint16_t      e_type;      // Type of ELF file
    uint16_t      e_machine;   // Target architecture
    uint32_t      e_version;   // ELF file version
    uint64_t      e_entry;     // Entry point virtual address
    uint64_t      e_phoff;     // Program header table file offset
    uint64_t      e_shoff;     // Section header table file offset
    uint32_t      e_flags;     // Processor-specific flags
    uint16_t      e_ehsize;    // ELF header size in bytes
    uint16_t      e_phentsize; // Size of program header entry
    uint16_t      e_phnum;     // Number of program header entries
    uint16_t      e_shentsize; // Size of section header entry
    uint16_t      e_shnum;     // Number of section header entries
    uint16_t      e_shstrndx;  // Section header string table index
} Elf64_Ehdr;

// Function to read and display ELF header
void display_elf_header(const char *filename) {
    int fd;
    Elf64_Ehdr header;

    // Open the file
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(98);
    }

    // Read ELF header
    if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
        fprintf(stderr, "Error reading ELF header from file: %s\n", filename);
        close(fd);
        exit(98);
    }

    // Check ELF magic number
    if (header.e_ident[0] != 0x7f || strncmp((char *)&header.e_ident[1], "ELF", 3) != 0) {
        fprintf(stderr, "%s: Not an ELF file\n", filename);
        close(fd);
        exit(98);
    }

    // Display ELF header information
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < 16; ++i)
        printf("%02x ", header.e_ident[i]);
    printf("\n");
    printf("  Class:                             ");
    switch (header.e_ident[4]) {
        case 1: printf("ELF32\n"); break;
        case 2: printf("ELF64\n"); break;
        default: printf("<unknown>\n"); break;
    }
    printf("  Data:                              %s\n", (header.e_ident[5] == 1) ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %u (current)\n", (unsigned int)header.e_ident[6]);
    printf("  OS/ABI:                            ");
    switch (header.e_ident[7]) {
        case 0: printf("UNIX - System V\n"); break;
        case 6: printf("UNIX - Solaris\n"); break;
        case 9: printf("UNIX - FreeBSD\n"); break;
        default: printf("<unknown: %u>\n", header.e_ident[7]); break;
    }
    printf("  ABI Version:                       %u\n", (unsigned int)header.e_ident[8]);
    printf("  Type:                              ");
    switch (header.e_type) {
        case 1: printf("REL (Relocatable file)\n"); break;
        case 2: printf("EXEC (Executable file)\n"); break;
        case 3: printf("DYN (Shared object file)\n"); break;
        default: printf("<unknown: %u>\n", header.e_type); break;
    }
    printf("  Entry point address:               0x%lx\n", (unsigned long)header.e_entry);

    // Close file descriptor
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    display_elf_header(argv[1]);
    return 0;
}

