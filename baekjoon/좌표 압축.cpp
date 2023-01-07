#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long arr[1000000], arrSorted[1000000], arrNoOverlap[1000000];

int comp(const void* a, const void* b) { return *(long long*)a > *(long long*)b ? 1 : 0; }

int main() {
    int n, i, j = 1;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }  // arr 에는 그냥 처음 입력ㅂ 다음

    memcpy(arrSorted, arr, sizeof(arr));  // arr 그대로 arrSorted 에 복사

    qsort(arrSorted, n, sizeof(long long), comp);  // arrSorted 는 오름차순

    arrNoOverlap[0] = arrSorted[0];

    for (i = 0; i < n; i++) {
        if (arrSorted[i] != arrNoOverlap[j - 1]) arrNoOverlap[j++] = arrSorted[i];
    }  // arr arrNoOverlap 은 정렬+ 중복하는수를 빼버린 결과.

    for (i = 0; i < n; i++) {
        int left = 0, right = j - 1, mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if(arr[i]==arrNoOverlap[mid]){
                printf("%d ",mid);
                break;
            }
            else{
                if(arr[i]<arrNoOverlap[mid]) right = mid-1;
                else left = mid+1;
            }
        }
    }
    return 0;
}