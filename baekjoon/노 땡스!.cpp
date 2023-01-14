#include <stdio.h>

int main(){
    int n,cnt=0,i,sum=0;
    int arr[33];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i =0;i<n;i++){
        if(arr[i+1]==arr[i]+1){
            cnt++;
            continue;
        }
        else{
            sum+= arr[i-cnt];
            cnt=0;
        }
    }
    printf("%d",sum);
    return 0;
}