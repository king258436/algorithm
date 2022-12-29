#include <stdio.h>
#include <stdlib.h>

int compA(const void* a, const void* b) {
    if (*(int*)a > *(int*)b)
        return 1;
    else
        return -1;
}  // 오름차순

int compB(const void* a, const void* b) {
    if (*(int*)a > *(int*)b)
        return -1;
    else
        return 1;
}

int main() {
    int n,sum=0;
    int *a, *b;
    scanf("%d", &n);
    a = (int*)malloc(sizeof(int)*n);
    b = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    qsort(a,n,sizeof(int),compA);
    qsort(b,n,sizeof(int),compB);

    for(int i=0;i<n;i++){
        sum+=a[i]*b[i];
    }
    printf("%d",sum);
}