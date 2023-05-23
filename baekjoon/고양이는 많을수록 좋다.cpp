#include <iostream>
using namespace std;
long long n=1;// 현재고양이
long long cnt=1; // 마법
long long res;// 목표 고양이

int main(){
    cin>> res;
    if(res==1) {
        cout<<1;
        return 0;
    }
    if(res==0) {
        cout<<0;
        return 0;
    }
    while(1){
        if(res-n<=n){
            break;
        }
        n*=2;
        cnt++;
    }
    cout<< cnt+1;
}