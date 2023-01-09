#include <stdio.h>
#include <math.h>

#define MAX 300000

int main(){
    int n=1,i,j;
    int arr[MAX]={0};
    for(i=2;i<=sqrt(MAX);i++){
        if(arr[i]==0){
            for(j=2;j*i<MAX;j++){
                arr[j*i]=1;
            }
        }
    }
    scanf("%d",&n);
    while(n!=0){
        int cnt=0;
        for(i=n+1;i<=2*n;i++){
            if(arr[i]==0) cnt++;
        }
        printf("%d\n",cnt);
        scanf("%d",&n);
    }
    return 0;
}