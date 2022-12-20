#include <stdio.h>

int cnt=0;

int rec(int n,int m){
    if(n>m){
        rec(n-m,m);
        cnt++;
    }
    else if(n<m){
        rec(n,m-n);
        cnt++;
    }
    else {
        cnt++;
        return 1;
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    rec(n,m);
    printf("%d",cnt);

}