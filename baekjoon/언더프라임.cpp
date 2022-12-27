#include <math.h>
#include <stdio.h>

#define size 100000

int main() {
    int arr[size] = {0}, a, b, i, j,num,underprime=0;
    arr[0]=1;
    arr[1]=1;
    for (i = 2; i <= sqrt(size); i++) {
        if (arr[i] == 0) {
            for (j = 2; i*j < size; j++) {
                arr[i*j]=1;
            }
        }
    }
    scanf("%d %d",&a,&b);
    for(i=a;i<=b;i++){
        num=i;
        int cnt=0;
        for(j=2;j<=num;j++){
            if(arr[num]==0){
                cnt++;
                break;
            }
            if(num%j==0){
                num/=j;
                cnt++;
                j=1;
            }
        }
        if(arr[cnt]==0) underprime++;
    }
    printf("%d",underprime);
    return 0;
}