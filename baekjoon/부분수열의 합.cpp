#include <stdio.h>
int arr[30];
int cnt =0;
int n,s;
void func(int cur, int tot){
    if(cur==n){
        if(tot==s){
            cnt++;
        }
        return;
    }
    func(cur+1,tot+arr[cur]);
    func(cur+1,tot);
}

int main(){
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    func(0,0);
    if(s==0) cnt--;
    printf("%d",cnt);
}