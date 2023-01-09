#include <stdio.h>
#include <string.h>

int main(){
    int n;
    int i;
    char temp,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        char arr[100000];
        char stack[100000];
        scanf("%s",arr);
        int atop = strlen(arr)-1;
        int stop = -1;
        while(atop>=0){
            stack[++stop]=arr[atop--];
            if(stop>=1){
                if(stack[stop]==stack[stop-1]){
                    stop=stop-2;
                }
            }
        }
        if(stop<0) cnt++;
    }
    printf("%d",cnt);
}