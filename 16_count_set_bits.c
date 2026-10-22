#include <stdint.h>
#include <stdio.h>
unsigned int count_flips(uint32_t a, uint32_t b){
    uint32_t x = a ^ b;
    unsigned int count = 0;
    while (x != 0){
        x &= x - 1;
        count++;
    }
    return count;
}

int main(void){
    uint32_t a = 10;
    uint32_t b = 7;
    printf("Flip bits = %u\n", count_flips(a, b));
    return 0;
}