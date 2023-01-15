#include <stdio.h>

int arr[100000];
int map[1000001];
int score[1000001];
int main(){
    int n,i,j;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        map[arr[i]]=1;
    }
    
    for(i=0;i<n;i++){
        for(j=2;j*arr[i]<=1000000;j++){
            score[j*arr[i]]-=1;
            if(map[j*arr[i]]==1) score[arr[i]]+=1;
        }
    }

    for(i=0;i<n;i++){
        printf("%d ",score[arr[i]]);
    }

}