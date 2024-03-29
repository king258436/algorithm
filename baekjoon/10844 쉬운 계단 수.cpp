#include <iostream>

using namespace std;
int dp[101][101];
int main(){
    int n;
    int sum=0;
    cin>> n;
    for(int i=1;i<=9;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            if(j==0) dp[i][j]=dp[i-1][j+1];
            else if(j==9) dp[i][j]= dp[i-1][j-1];
            else dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
            dp[i][j]= dp[i][j]%1000000000;
        }
    }
    for(int i=0;i<=9;i++){
        sum= (sum+dp[n][i])%1000000000;
    }
    cout<< sum;
}