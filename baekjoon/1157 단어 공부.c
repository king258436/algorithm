#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char str[1000001];
int alpha[26];
int main() {
	char ans;
	int len;
	int max = 0;
	scanf("%s", &str);// str[] 에 문자열 입력받음
	len = strlen(str);
	for (int i = 0; i < len; i++){
		if (str[i] > 95) str[i] -= 32;
	}//str[]에 받은 문자열 전부다 대문자로 교체.
	for (int i = 0; i < len; i++) {
		alpha[str[i] - 'A']++; //str 배열에서 알파벳 나온 개수를 alpha에 넣음.
	}
	for (int i = 0; i < 26; i++) {
		if (alpha[i] == max) ans = '?';
		else if (alpha[i] > max) {
			max = alpha[i];
			ans = 'A' + i;
		}
	}
	printf("%c", ans);

	return 0;
}
