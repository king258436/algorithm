#include <stdio.h>
#include <stdlib.h>

typedef struct _plug {
    int cnt;
    int arr[100000];
    long long sum;
} Plug;

void init(Plug* plug) { plug->sum = 0; }

int comp(const void* a, const void* b) { return *(int*)a > *(int*)b ? 0 : 1; }

int main() {
    int i, j, save;
    Plug aplug, bplug;

    scanf("%d %d", &aplug.cnt, &bplug.cnt);

    for (i = 0; i < aplug.cnt; i++) {
        scanf("%d", &aplug.arr[i]);
    }
    for (i = 0; i < bplug.cnt; i++) {
        scanf("%d", &bplug.arr[i]);
    }

    qsort(aplug.arr, aplug.cnt, sizeof(int), comp);
    qsort(bplug.arr, bplug.cnt, sizeof(int), comp);  // 정렬완료.

    init(&bplug);
    init(&aplug);  // 초기화 완료.

    for (i = 0; aplug.sum < bplug.cnt; i++) {
        if(i>=aplug.cnt) break;
        aplug.sum += aplug.arr[i];
        save = i;
    }  //

    if (aplug.sum < bplug.cnt) {
        for (i = 0; i < aplug.sum; i++) {
            if(i>=bplug.cnt) break;
            bplug.sum+=bplug.arr[i];
        }
    }  // 만약 b 플러그를 꽂을 공간인 a플러그의 콘센트가 부족할경우
    else {
        for(i=0;i<bplug.cnt;i++){
            bplug.sum+=bplug.arr[i];
        }
    }
    printf("%lld",bplug.sum-save);
}