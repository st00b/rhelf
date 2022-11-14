#include "verify_elf.h"

bool verify_elfnumber(unsigned char* buffer) {
    return(buffer[0] == '\x7f' && buffer[1] == '\x45' && buffer[2] == '\x4c' && buffer[3] == '\x46');
}
bool elffile_init(ELF_FILE *f_elf) {
    FILE *fElf = fopen(f_elf->path, "rb");
    if (!fElf) {
        return false;
    }

    f_elf->header_elf = malloc(sizeof(Elf64_header));
    if (f_elf->header_elf == NULL) {
        return false;
    }

    /* REALIZAR TESTE */
    fread(f_elf->header_elf, sizeof(Elf64_header), 1, fElf);
    fclose(fElf);
}
void verify_tipe(uint16_t e_type) {
    printf("Object file type: ");
    switch(e_type) {
        case 1:
            printf("Relocatable file\n");
            break;

        case 2:
            printf("Executable File (only if compiled with a -no-pie switch)\n");
            break;

        case 3:
            printf("Shared object file (includes executables compiled with PIE active)\n");
            break;

        case 4:
            printf("Core File\n");
            break;
        
        case 5:
            printf("Number of defined types\n");
            break;

        default:
            printf("Others. See documentation at: /usr/include/elf.h\n");
    }
}
void verify_machine(uint16_t e_machine) {
    printf("Machine: ");
    switch (e_machine) {
        case 62:
            printf("AMD x86-64 architecture\n");
            break;

        case 3:
            printf("Intel 80386\n");
            break;

        default:
            printf("Others. See documentation at: /usr/include/elf.h\n");
            break;
    }
}
void verify_version(uint16_t e_version) {
    printf("ELF Version: ");

    switch (e_version)
    {
    case 0:
        printf("Invalid File!\n");
        break;

    case 1:
        printf("Current Version (1.0)\n");
        break;
    }
}
void verify_entrypoint(uint64_t e_entry) {
    printf("Entry Point: ");
    printf("0x%lx\n", e_entry);
}
void verify_phoff(uint64_t e_phoff) {
    printf("Program header table offset: ");
    printf("%ld bytes inside the file\n", e_phoff);
}
void verify_shoff(uint64_t e_shoff){
    printf("Section header table file offset ");
    printf("%ld bytes insine the file\n", e_shoff);
}
void verify_flags(uint16_t e_flag) {
    printf("Flags: ");
    printf("0x%04x \n", e_flag);
}
void verify_ehsize(uint16_t e_ehsize) {
    printf("ELF header: %d bytes \n", e_ehsize);
}
void verify_phentsize(uint16_t e_phentsize) {
    printf("Program header table entry size: %d bytes\n", e_phentsize);
}
void verify_phnum(uint16_t e_phnum) {
    printf("Program header table entry count: %d\n", e_phnum);
}
void verify_shentsize(uint16_t e_shentsize) {
    printf("Section header table entry size: %d bytes\n", e_shentsize);
}
void verify_shnum(uint16_t e_shnum) {
    printf("Section header table entry count: %d\n", e_shnum);
}
void verify_shstrndx(uint16_t e_shstrndx) {
    printf("Section header string table index: %d\n", e_shstrndx);
}
void verify_ident(ELF_FILE elf_file) {
    for(int i = 0; i < 16; i++) {
        printf("%02x ", elf_file.header_elf->e_ident[i]);
    }

    printf("\n");
}