#include <stdio.h>

typedef struct _lf{
    int weight;
    int value;
}WV;

int value[101][100001];
WV thing[101];

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int main(){
    int n;
    int i,j,k;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d %d",&thing[i].weight,&thing[i].value);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            int wi=thing[i].weight;
            int vi=thing[i].value;

            if(wi>j) value[i][j]=value[i-1][j];
            else {
                value[i][j]=max(value[i-1][j],vi+value[i-1][j-wi]);
            }
        }
    }
    printf("%d",value[n][k]);
}