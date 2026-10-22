#include <stdio.h>
void keep_alphabets(char str[]) {
    int read = 0;
    int write = 0;
    while (str[read] != '\0') {
        char ch = str[read];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            str[write++] = str[read];
        }
        read++;
    }
    str[write] = '\0';
}
int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    keep_alphabets(str);
    printf("String with only alphabets: %s\n", str);
    return 0;
}