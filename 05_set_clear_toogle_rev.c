#include<stdio.h>
#include<stdint.h>
uint32_t set_bit(uint32_t n, unsigned int k){
    if (k >= 32)
        return n;
    return n | (UINT32_C(1) << k);
}

uint32_t clear_bit(uint32_t n, unsigned int k){
    if (k >= 32)
        return n;
    return n & ~(UINT32_C(1) << k);
}

uint32_t toggle_bit(uint32_t n, unsigned int k){
    if (k >= 32)
        return n;
    return n ^ (UINT32_C(1) << k);
}

uint32_t reverse_bits(uint32_t n){
    uint32_t reversed = 0;
    for (int i = 0; i < 32; i++){
        reversed = (reversed << 1) | (n & 1);
        n >>= 1;
    }
    return reversed;
}

int main(void){
    uint32_t n;
    unsigned int k;
    printf("Enter a number: ");
    scanf("%u", &n);
    printf("Enter bit position (0-31): ");
    scanf("%u", &k);
    printf("Original number: %u\n", n);
    printf("After setting bit %u: %u\n", k, set_bit(n, k));
    printf("After clearing bit %u: %u\n", k, clear_bit(n, k));
    printf("After toggling bit %u: %u\n", k, toggle_bit(n, k));
    printf("After reversing bits: %u\n", reverse_bits(n));
    return 0;
}