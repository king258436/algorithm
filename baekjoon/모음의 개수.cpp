#include <stdio.h>

main() {
	char arr[255];
	while (1) {
		int count = 0;		//count: 모음의 개수
		gets(arr);
		if (arr[0] == '#')	//#을 입력받으면 실행 종료
			break;
		for (int i = 0; arr[i] != '\0'; i++) {
			if (arr[i] == 'a' || arr[i] == 'A')
				count++;
			else if (arr[i] == 'e' || arr[i] == 'E')
				count++;
			else if (arr[i] == 'i' || arr[i] == 'I')
				count++;
			else if (arr[i] == 'o' || arr[i] == 'O')
				count++;
			else if (arr[i] == 'u' || arr[i] == 'U')
				count++;
			}
		printf("%d\n", count);
	}
	return 0;
}