#include <iostream>

using namespace std;
int main(){
    int t;
    cin>> t;
    while(t--){
        int n,m;
        int dp[10001]={0,};
        int coin[21]={0,};
        dp[0]=1;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>coin[i];
        }
        cin>> m;
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                if(j-coin[i]>=0){
                    dp[j]+=dp[j-coin[i]];
                }
            }
        }
        cout<<dp[m]<<endl;
    }
}