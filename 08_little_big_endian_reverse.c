#include <stdio.h>
#include <stdint.h>
uint32_t reverse_bytes(uint32_t x){
    return ((x & UINT32_C(0x000000FF)) << 24) |
           ((x & UINT32_C(0x0000FF00)) << 8)  |
           ((x & UINT32_C(0x00FF0000)) >> 8)  |
           ((x & UINT32_C(0xFF000000)) >> 24);
}

int main(void){
    uint32_t x = UINT32_C(0x12345678);
    printf("Byte reversed: 0x%08X\n", (unsigned int)reverse_bytes(x));
    return 0;
}
