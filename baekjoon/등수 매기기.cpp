#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
    if(*(int*)a<*(int*)b) return -1;
    else return 1;
}

int main(){
    int n,i;
    int *predict;
    long long sum=0;

    scanf("%d",&n);

    predict = (int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++){
        scanf("%d",&predict[i]);
    }
    
    qsort(predict,n,sizeof(int),compare);

    for(i=0;i<n;i++){
        if(predict[i]>i+1){
            sum+=predict[i]-(i+1);
        }
        else sum+= i+1-predict[i];
    }
    printf("%lld",sum);
    return 0;
}