#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define max 1000000

int main() {

    char ch[max] = {0,};
    int score[26] = {0,};
    int index = 0;
    int flag = 0;

    scanf("%s", ch);

    int len = strlen(ch);

    for (int i = 0; i < len; i++) {
        if (ch[i] >= 'a') { // 대문자로 변경
            ch[i] -= 32;
        }
    }

    for (int i = 0; i < len; i++) {
        score[ch[i] - 65]++;
    }

    index = 0;
    for (int i = 1; i < 26; i++) {
        if (score[index] < score[i]) {
            index = i; // 현재 i값으로 저장
            flag = 0; // 플래그가 0이 아닌, 1이상일 경우 ? 출력하기 위함
        } else if (score[index] > score[i]) {
            continue;
        } else if (score[index] == score[i]) {
            flag++;
        }
    }

    if (flag == 0) {
        printf("%c", index + 65);
    } else {
        printf("?");
    }


    return 0;
}