#include<stdio.h>
#define multiply_by_9(x) ((x << 3) + x)
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Result: %d\n", multiply_by_9(n));
    return 0;
}