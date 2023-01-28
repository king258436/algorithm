#include <stdio.h>
#include <stdlib.h>

int n,m;
int arr[10];
int visited[100001];
int result[10];

int compare(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

void dfs(int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            printf("%d ",result[i]);
        }
        printf("\n");
    }
    else{
        int xx=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=xx){
                result[depth]=arr[i];
                xx=result[depth];
                dfs(depth+1);
            }
        }
    }
}

int main(){
    int i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    qsort(arr,n,sizeof(int),compare);
    dfs(0);
    return 0;
}