#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void usage();
void reading_error();
void allocating_memory_error();

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

int main(int argc, char *argv[]) {
    
    Elf64_header elf64header;
    FILE *bFile;
    char *bBuffer;
    
    if (argc < 2) {
        usage();
    }

    bFile = fopen(argv[1], "rb");

    if (bFile == NULL) {
        reading_error();
    }

    bBuffer = malloc(sizeof(elf64header));

    if (bBuffer == NULL) {
        allocating_memory_error();
    }

    fread(bBuffer, 64, 1, bFile);

    return 0;
}

void usage() {
    printf("Modo de usar: ./rhelf <file>\n");
    exit(1);
}

void reading_error() {
    printf("Erro ao realizar leitura do binário!\n");
    exit(1);
}

void allocating_memory_error() {
    printf("Falha na alocação de memória\n");
    exit(1);
}
