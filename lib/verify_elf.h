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
void verify_ident(ELF_FILE);
void verify_tipe(uint16_t e_type);
void verify_machine(uint16_t e_machine);
void verify_version(uint16_t e_version);
void verify_entrypoint(uint64_t e_entry);
void verify_phoff(uint64_t e_phoff);
void verify_shoff(uint64_t e_shoff);
void verify_flags(uint16_t e_flag);
void verify_ehsize(uint16_t e_ehsize);
void verify_phentsize(uint16_t e_phentsize);
void verify_phnum(uint16_t e_phnum);
void verify_shentsize(uint16_t e_shentsize);
void verify_shnum(uint16_t e_shnum);
void verify_shstrndx(uint16_t e_shstrndx);