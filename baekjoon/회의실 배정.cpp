#include <stdio.h>
#include <stdlib.h>

typedef struct meme{
    int s;
    int e;
}mem;

int comp(const void* a,const void *b){
    if(((mem*)a)->e>((mem*)b)->e) return 1;
    if(((mem*)a)->e==((mem*)b)->e){
        if(((mem*)a)->s>((mem*)b)->s) return 1;
        else return -1;
    }
    else return -1;
}

int main(){
    int n;
    int i,j;
    mem *con;
    int beforeE=0;
    int cnt=0;

    scanf("%d",&n);

    con= (mem*)malloc(sizeof(mem)*n);

    for(i=0;i<n;i++){
        scanf("%d %d",&con[i].s,&con[i].e);
    }

    qsort((mem*)con,n,sizeof(mem),comp);

    for(i=0;i<n;i++){
        if(beforeE<=con[i].s){
            beforeE=con[i].e;
            cnt++;
        }
    }
    printf("%d",cnt);

}