#include <stdio.h>
#include <stdlib.h>

// 머지소트 -> 분할
void Merge(int*arr,int left, int mid, int right);
void MergeSort(int *arr, int left, int right);

void MergeSort(int *arr, int left, int right) {
    int mid = (left + right) / 2;

    if (left < right) {
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
    }

    Merge(arr,left,mid,right);

}

//머지 -> 합병
void Merge(int*arr,int left, int mid, int right){
    int lIdx=left,rIdx=mid+1;
    int i;

    int *sortArr=(int*)malloc(sizeof(int)*(right+1));
    int sIdx=left;

    while(lIdx<=mid&&rIdx<=right){
        if(arr[lIdx]>arr[rIdx]) sortArr[sIdx++]=arr[rIdx++];
        else sortArr[sIdx++]=arr[lIdx++];
    }

    while(lIdx<=mid){
        sortArr[sIdx++]=arr[lIdx++];
    }
    while(rIdx<=right){
        sortArr[sIdx++]=arr[rIdx++];
    }

    for(i=left;i<=right;i++) arr[i]=sortArr[i];

    free(sortArr);
}

int main(){
    int n;
    int i;
    scanf("%d",&n);
    int *arr=(int*)malloc(sizeof(int)*(n+1));

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    MergeSort(arr,0,n-1);

    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}