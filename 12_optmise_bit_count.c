#include <stdint.h>
#include <stdio.h>
uint32_t count_bits(uint32_t value){
    uint32_t count = 0;
    while (value != 0){
        value &= value - 1;
        count++;
    }
    return count;
}

int main(void){
    uint32_t value;
    printf("Enter a number: ");
    scanf("%u", &value);
    printf("Set bits = %u\n",(unsigned int)count_bits(value));
    return 0;
}