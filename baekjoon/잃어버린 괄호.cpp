#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[51], num[6];
    int flag = 0, sum = 0, j = 0;

    scanf("%s", str);

    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
            if (flag == 0) {
                sum += atoi(num);
                memset(num, 0, sizeof(char) * 6);
            } 
            else {
                sum -= atoi(num);
                memset(num, 0, sizeof(char) * 6);
            }

            j=0;

            if (str[i] == '-') flag = 1;

        } 
        else {
            num[j] = str[i];
            j++;
        }
    }
    printf("%d",sum);
    return 0;
}