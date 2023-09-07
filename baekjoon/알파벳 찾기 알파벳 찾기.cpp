#include<stdio.h>
#include<string.h>

char str[101];

int main() {
    scanf("%s", str);
    for (int i = 97; i <= 122; i++) {
        int flag = 0;
        for (int j = 0; j < strlen(str); j++) {
            if (i == (int) str[j]) {
                flag = 1;
                printf("%d ", j);
                break;
            }
        }
        if (flag == 0) {
            printf("-1 ");
        }
    }
}