#include <iostream>
using namespace std;

int arr[10000];
int dp[10001];

int maxVal(int a,int b, int c){
    if(a>=b&&a>=c) return a;
    else if(b>=a&&b>=c) return b;
    else return c;
}

int main(){
    int n;
    cin>> n;
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    dp[1]=arr[0];
    dp[2]=arr[0]+arr[1];
    for(int i=3;i<=n;i++){
        dp[i]=maxVal(dp[i-1],dp[i-2]+arr[i-1],dp[i-3]+arr[i-2]+arr[i-1]);
    }
    cout<< dp[n];
}
