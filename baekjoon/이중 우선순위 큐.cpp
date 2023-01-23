#include <stdio.h>

typedef struct _heap {
    int value;
    int dataIdx;
} heap;

typedef struct _data {
    int deleteFlag;
    int value;
} Data;

Data data[1000000];
int dcnt;

heap maxHeap[1000000];
int maxSize;
heap minHeap[1000000];
int minSize;

void swap(heap *parent, heap *child) {
    heap temp = *parent;
    parent = child;
    child = &temp;
}

void minPush(int data, int dcnt) {
    minHeap[++minSize].value = data;
    minHeap[minSize].dataIdx = dcnt;
    int child = minSize;
    while (child != 1) {
        int parent = child / 2;
        if (minHeap[child].value >= minHeap[parent].value) break;

        heap tmp = minHeap[parent];
        minHeap[parent] = minHeap[child];
        minHeap[child] = tmp;

        child = parent;
    }
}

heap minPop() {
    heap root = minHeap[1];
    minHeap[1] = minHeap[minSize];
    minHeap[minSize--].value = 0x7fffffff;
    int parent = 1;
    while (2 * parent <= minSize) {
        int lc = 2 * parent, rc = 2 * parent + 1;
        int minchild = lc;
        if (rc <= minSize && minHeap[lc].value > minHeap[rc].value) minchild = rc;
        if (minHeap[minchild].value >= minHeap[parent].value) break;

        heap tmp = minHeap[parent];
        minHeap[parent] = minHeap[minchild];
        minHeap[minchild] = tmp;
        parent = minchild;
    }
    return root;
}

heap maxPop() {
    heap root = maxHeap[1];
    maxHeap[1] = maxHeap[maxSize];
    maxHeap[maxSize--].value = 0x80000000;
    int parent = 1;
    while (2 * parent <= maxSize) {
        int lc = 2 * parent, rc = 2 * parent + 1;
        int maxchild = lc;
        if (rc <= maxSize && maxHeap[lc].value < maxHeap[rc].value) maxchild = rc;
        if (maxHeap[maxchild].value <= maxHeap[parent].value) break;

        heap tmp = maxHeap[parent];
        maxHeap[parent] = maxHeap[maxchild];
        maxHeap[maxchild] = tmp;
        parent = maxchild;
    }
    return root;
}

void maxPush(int data, int dcnt) {
    maxHeap[++maxSize].value = data;
    maxHeap[maxSize].dataIdx = dcnt;
    int child = maxSize;
    while (child != 1) {
        int parent = child / 2;
        if (maxHeap[child].value <= maxHeap[parent].value) break;

        heap tmp = maxHeap[parent];
        maxHeap[parent] = maxHeap[child];
        maxHeap[child] = tmp;

        child=parent;
    }
}

int main() {
    int num, t, k;
    char commend;
    int i, j;
    int numOfData;

    scanf("%d", &t);

    for (i = 0; i < t; i++) {
        maxSize = minSize = dcnt = numOfData = 0;
        scanf("%d", &k);

        for (j = 0; j < k; j++) {
            scanf(" %c %d", &commend, &num);

            if (commend == 'I') {
                data[dcnt].value = num;
                data[dcnt].deleteFlag = 0;

                maxPush(num, dcnt);
                minPush(num, dcnt);

                dcnt++;
                numOfData++;
            }

            else {
                if (numOfData == 0) {
                    maxSize = 0;
                    minSize = 0;
                    continue;
                }

                while (data[maxHeap[1].dataIdx].deleteFlag) maxPop();
                while (data[minHeap[1].dataIdx].deleteFlag) minPop();

                heap temp;

                if (num == 1) {
                    temp = maxPop();
                    data[temp.dataIdx].deleteFlag = 1;
                } else {
                    temp = minPop();
                    data[temp.dataIdx].deleteFlag = 1;
                }
                numOfData--;
            }
        }
        if (numOfData) {
            while (data[maxHeap[1].dataIdx].deleteFlag == 1) maxPop();
            while (data[minHeap[1].dataIdx].deleteFlag == 1) minPop();

            heap maxvalue = maxPop();
            heap minvalue = minPop();

            printf("%d %d\n",maxvalue.value, minvalue.value);
        }
        else printf("EMPTY\n");
    }
}