#include <stdio.h>
#include <stdlib.h>

int cnt = 0, result = 0, k;
void MergeTwoArea(int arr[], int left, int mid, int right) {
    int fIdx = left;
    int rIdx = mid + 1;
    int i;

    int* sortArr = (int*)malloc(sizeof(int) * (right + 2));
    int sIdx = left;

    while (fIdx <= mid && rIdx <= right) {
        if (arr[fIdx] <= arr[rIdx]) {
            sortArr[sIdx] = arr[fIdx++];
        } else {
            sortArr[sIdx] = arr[rIdx++];
        }

        sIdx++;
    }

    if (fIdx > mid) {
        for (i = rIdx; i <= right; i++, sIdx++) {
            sortArr[sIdx] = arr[i];
        }
    } else {
        for (i = fIdx; i <= mid; i++, sIdx++) {
            sortArr[sIdx] = arr[i];
        }
    }

    for (i = left; i <= right; i++) {
        arr[i] = sortArr[i];
        cnt++;
        if (cnt == k) result = arr[i];
        if (cnt<k) result = -1;
    }

    free(sortArr);
}

void MergeSort(int arr[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        MergeTwoArea(arr, left, mid, right);
    }
}

int main(void) {
    int arr[500000];
    int i, n;
    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    MergeSort(arr, 0, n - 1);

    printf("%d", result);
    return 0;
}