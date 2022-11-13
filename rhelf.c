#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "lib/verify_elf.h"

void usage(char *msg_error) {
    fprintf(stderr, "%s\n", msg_error);
    exit(1);
}

int main(int argc, char *argv[]) {
    FILE *bFile;
    unsigned char bBuffer_initialbytes[16];

    if (argc != 2) {
        usage("Utilize: ./rhelf <binary_path>");
    }

    bFile = fopen(argv[1], "rb");

    if (bFile == NULL) {
        usage("Arquivo não encontrado ou não há permissão para leitura!\n");
    }

    if(fread(bBuffer_initialbytes, 16, 1, bFile) != 1) {
        usage("Falha na leitura dos primeiros 16 bytes do arquivo!\n");
    }

    if (verify_elfnumber(bBuffer_initialbytes) != 1) {
        usage("Magic Number não reconhecido!\n");
    }


    fclose(bFile);
    return 0;
}