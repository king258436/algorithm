#include <iostream>
#include <algorithm>
using namespace std;
int value[10001];
int dp[10001];
int main(){
    int n;
    cin>> n;
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }

    for(int i=1;i<=n;i++){
        dp[i]=value[i];
        for(int j=1;j<=i;j++){
            dp[i]=min(dp[i],dp[i-j]+dp[j]);
        }
    }
    cout<<dp[n];
}