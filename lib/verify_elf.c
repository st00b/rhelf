#include "verify_elf.h"

bool verify_elfnumber(unsigned char* buffer) {
    return(buffer[0] == '\x7f' && buffer[1] == '\x45' && buffer[2] == '\x4c' && buffer[3] == '\x46');
}