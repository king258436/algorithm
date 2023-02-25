#include <iostream>

using namespace std;
int n,k;
int arr[100];
int dp[10001];

int main(){
    int i,j;
    dp[0]=1;
    cin>> n>>k;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        for(j=arr[i];j<=k;j++){
            dp[j]+=dp[j-arr[i]];
        }
    }
    cout<< dp[k];
}