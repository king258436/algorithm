#include <stdio.h>
#include <stdlib.h>

#define max 100001

typedef struct _heap {
    int arr[max];
    int size;
} heap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(heap *hp, int data) {
    int here = ++hp->size;  // 힙의 맨 마지막에 위치.
    while (here != 1 && abs(data) <= abs(hp->arr[here / 2])) {
        if (abs(data) == abs(hp->arr[here / 2])) {
            if (data > hp->arr[here / 2]) break;
        }
        hp->arr[here] = hp->arr[here / 2];
        here /= 2;
    }
    hp->arr[here] = data;
}

int delete(heap *hp) {
    if (hp->size == 0) return 0;
    int rdata = hp->arr[1];
    hp->arr[1] = hp->arr[hp->size--];
    int parent = 1;
    int child;

    while (1) {
        child = parent * 2;

        if (child + 1 <= hp->size && abs(hp->arr[child]) > abs(hp->arr[child + 1])) child++;
        else if(child+1<=hp->size && abs(hp->arr[child])==abs(hp->arr[child+1])){
            if(hp->arr[child]>hp->arr[child+1]) child++;
        }

        if (child > hp->size || abs(hp->arr[child]) > abs(hp->arr[parent])) break;  // 완전이진트리 이거나, 자식노드가 공노드면 브릭
        else if(child > hp->size || abs(hp->arr[child]) == abs(hp->arr[parent])){
            if(hp->arr[child] > hp->arr[parent]) break;
        }

        swap(&hp->arr[parent], &hp->arr[child]);
        parent = child;
    }

    return rdata;
}

int main() {
    int n, num;
    int i, j;
    heap hp;
    hp.size = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num == 0)
            printf("%d\n", delete (&hp));
        else
            insert(&hp, num);
    }
    return 0;
}