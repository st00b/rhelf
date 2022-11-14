#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "lib/verify_elf.h"

void error(char *msg_error) {
    fprintf(stderr, "%s\n", msg_error);
    exit(1);
}

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        error("Utilize: ./rhelf <binary_path>");
    }

    FILE *bBuffer;

    ELF_FILE elf;

    elf.path = argv[1];
    elffile_init(&elf);

    if(!verify_elfnumber(elf.header_elf->e_ident)) {
        error("Magic Numbers não reconhecidos");
    }

    verify_ident(elf);
    verify_tipe(elf.header_elf->e_type);
    verify_machine(elf.header_elf->e_machine);
    verify_version(elf.header_elf->e_version);
    verify_entrypoint(elf.header_elf->e_entry);
    verify_phoff(elf.header_elf->e_phoff);
    verify_shoff(elf.header_elf->e_shoff);
    verify_flags(elf.header_elf->e_eflags);
    verify_ehsize(elf.header_elf->e_ehsize);
    verify_phentsize(elf.header_elf->e_phentsize);
    verify_phnum(elf.header_elf->e_phnum);
    verify_shentsize(elf.header_elf->e_shentsize);
    verify_shnum(elf.header_elf->e_shnum);
    verify_shstrndx(elf.header_elf->e_shstrndx);

    
    return 0;
}