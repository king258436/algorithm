#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int dp[1001][1001];

int main(){
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
            else{
                dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    cout << dp[a.length()][b.length()];

}