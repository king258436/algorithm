#include <stdio.h>
#include <stdlib.h>

int n,m;
int arr[10];
int visited[100001];
int result[10];

int compare(const void* a, const void* b){
    return *(int*)a-*(int*)b;
}

void dfs(int depth,int min){
    if(depth==m){
        for(int i=0;i<m;i++){
            printf("%d ",result[i]);
        }
        printf("\n");
    }
    else{
        int xx=0;
        for(int i=0;i<n;i++){
            if(!visited[i]&&arr[i]>xx&&arr[i]>=min){
                result[depth]=arr[i];
                visited[i]=1;
                xx=result[depth];
                min=result[depth];
                dfs(depth+1,min);
                visited[i]=0;
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
    dfs(0,0);
    return 0;
}