#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _point{
    int x;
    int y;
}point;

int comp(const void* a,const void *b){
    if(*(double*)a>*(double*)b) return 1;
    else return -1;
}

int main(){
    point p[4];
    int n;
    double arr[6];
    int num=-1;
    scanf("%d",&n);
    for(int k=0;k<n;k++){
        scanf("%d %d",&p[0].x,&p[0].y);
        scanf("%d %d",&p[1].x,&p[1].y);
        scanf("%d %d",&p[2].x,&p[2].y);
        scanf("%d %d",&p[3].x,&p[3].y);
        for(int i=0;i<4;i++){
            for(int j=0;j<i;j++){
                arr[++num]=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
            }
        }
        qsort(arr,6,sizeof(double),comp);
        if(arr[0]==arr[1]&&arr[0]==arr[2]&&arr[0]==arr[3]&&arr[4]==arr[5]){
            printf("1\n");
        }
        else printf("0\n");
        num=-1;
    }
    return 0;

}
