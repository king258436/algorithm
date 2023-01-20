#include <stdio.h>
#define INF 9999999;
int main(){
    int n;
    int map[100][100];
    int i,j,k;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&map[j][i]);
        }
    }

    for(k=0;k<n;k++){//k = 지나가는 정점.
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(map[j][k]&&map[k][i]) map[j][i]=1;
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",map[j][i]);
        }
        printf("\n");
    }
    return 0;
}