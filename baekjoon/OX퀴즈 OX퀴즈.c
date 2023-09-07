#include<stdio.h>
#include<string.h>

int n;
char str[100];

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        int score = 0;
        int con = 0;
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == 'O') {
                score += (++con);
            } else if (str[i] == 'X') {
                con = 0;
            }
        }
        printf("%d\n", score);
    }

}