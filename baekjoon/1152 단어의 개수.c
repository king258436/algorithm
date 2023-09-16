#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char arr[1000000];
	int count = 1;
	scanf("%[^\n]s", &arr);
	for (int i = 0; i < strlen(arr); i++)
		if (arr[i] == ' ') count++;
	if (arr[0] == ' ') count--;
	if (arr[strlen(arr) - 1] == ' ') count--;
	printf("%d", count);

}