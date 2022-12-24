#include <stdio.h>
#include <string.h>

int main(){
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int flag=1;
        char arr[101];
        scanf("%s",arr);
        for(int j=0;j<strlen(arr);j++){
            for(int k=j+1;k<strlen(arr);k++){
                if(arr[j]==arr[k]&&arr[k-1]!=arr[j]){
                    flag=0;
                    break;
                }
            }
            if(flag==0) break;
            if(j==strlen(arr)-1){
                cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;

}