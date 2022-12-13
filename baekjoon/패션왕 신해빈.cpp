#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str_kind, str_name[21], *arr_kind[31];//
    int t, n, i, j, k, numOfKind = 0, arr_num[31] = {0}, flag = 0, sum = 0;
    scanf("%d", &t);

    for (i = 0; i < t; i++) {  // 테스트 케이스만큼 반복.
        numOfKind = 0;
        sum = 1;
        flag = 0;
        scanf("%d", &n);

        for (j = 0; j < n; j++) {  // 옷의 갯수 n 만큼 입력받음.
            scanf("%s", str_name);
            str_kind = (char*)malloc(21*sizeof(char));
            scanf("%s", str_kind);  // 이름, 종류 입력받음.

            for (int k = 0; k < numOfKind; k++) {
                if (!strcmp(arr_kind[k], str_kind)) {  // 이미 있는 종류입니다.
                    arr_num[k]++;
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                arr_num[numOfKind] = 1;          // 종류에 옷하나 추가.
                arr_kind[numOfKind] = str_kind;  // 포인터 배열 arr_kind에 kind주솟값 넘겨줌.!!!!!!
                numOfKind++;                     // 종류 1개추가.
            }
            flag = 0;
        }
        for (j = 0; j < numOfKind; j++) {
            sum *= (arr_num[j] + 1);
        }
        sum--;
        printf("%d\n", sum);
    }
    return 0;
}
