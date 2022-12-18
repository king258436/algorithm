#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
    long long n = 0, k, count = 0, num, i, flag, arr[10], new;
    while (scanf("%lld", &n) != EOF) {
        k = 0;
        flag = 0;
        count = 0;
        memset(arr, 0, 10 * sizeof(long long));  // 새로운 n이 들어오면 초기화 문제없음.
        while (flag == 0) {
            k++;
            new = n * k;
            num = new;
            count = 0;

            while (num != 0) {
                num /= 10;
                ++count;
            }  // 몇 자리수 인지 세기

            for (i = 0; i < count; i++) {
                arr[(new / (long long)pow(10, (double)i)) % 10] = 1;
            }  // 각 자릿수마다 어떤 숫자가 들어가있는지 확인.

            for (i = 0; i < 10; i++) {
                if (arr[i] == 0) break;
                if (i == 9 && arr[i] == 1) flag = 1;
            }
        }
        printf("%lld\n", k);
    }
    return 0;
}