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