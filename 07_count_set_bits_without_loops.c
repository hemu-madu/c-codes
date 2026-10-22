#include<stdio.h>
#include<stdint.h>
int main(){
    uint32_t n;
    printf("Enter a number: ");
    scanf("%u", &n);
    printf("%d\n", __builtin_popcount(n));
    return 0;
}