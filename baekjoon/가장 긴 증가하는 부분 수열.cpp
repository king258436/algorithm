#include <stdio.h>
int arr[1001];
int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int LIS[1001];
    LIS[0]=1;
    for(int i=1;i<n;i++){
        LIS[i]=1;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                LIS[i]=max(LIS[i],LIS[j]+1);
            }
        }
    }
    int max=1;
    for(int i=0;i<n;i++){
        if(max<LIS[i]) max=LIS[i];
    }
    printf("%d",max);
}