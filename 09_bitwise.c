#include <stdio.h>
#include <stdint.h>
#define ENABLE_MASK  UINT32_C(0x00000001)
#define MODE_MASK    UINT32_C(0x000000F0)
#define MODE_SHIFT   4U
static volatile uint32_t REG = 0;
int main(void){
    REG |= ENABLE_MASK;
    REG &= ~ENABLE_MASK;
    uint32_t enable = REG & ENABLE_MASK;
    uint32_t mode = (REG & MODE_MASK) >> MODE_SHIFT;
    REG = (REG & ~MODE_MASK) | ((UINT32_C(5) << MODE_SHIFT) & MODE_MASK);
    REG ^= ENABLE_MASK;
    printf("Register = 0x%08X\n", (unsigned int)REG);
    printf("ENABLE = %u\n", (unsigned int)enable);
    printf("MODE = %u\n", (unsigned int)mode);
    return 0;
}