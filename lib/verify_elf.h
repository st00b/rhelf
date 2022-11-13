#include <stdbool.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1);

typedef struct {
    unsigned char e_ident[16];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_eflags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_header;

typedef struct {
    char *path;
    Elf64_header *header_elf;
} ELF_FILE;

#pragma pack(pop);

bool verify_elfnumber(unsigned char* buffer);

bool elffile_init(ELF_FILE *f_elf);