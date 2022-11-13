#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "lib/verify_elf.h"

void usage(char *msg_error) {
    fprintf(stderr, "%s\n", msg_error);
    exit(1);
}

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        usage("Utilize: ./rhelf <binary_path>");
    }

    ELF_FILE elf;

    elf.path = argv[1];
    elffile_init(&elf);

    for(int i = 0; i < 16; i++) {
        printf("%x\n", elf.header_elf->e_ident[i]);
    }
    
    
    // printf("\n");
    return 0;
}