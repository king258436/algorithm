#include <iostream>
#include <algorithm>

using namespace std;
int dp[600][600];
int arr[600][600];
int res;
int main(){
    int n,i,j;
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cin>>arr[i][j];
        }
    }
    dp[1][1]=arr[1][1];
    res=arr[1][1];
    for(i=2;i<=n;i++){
        for(j=1;j<=i;j++){
            if(j==1){
                dp[i][j]=dp[i-1][j]+arr[i][j];
            }
            else if(j==i){
                dp[i][j]= dp[i-1][j-1]+arr[i][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+arr[i][j];
            }
            if(dp[i][j]>res) res=dp[i][j];
        }
    }
    cout<< res;
    return 0;
}