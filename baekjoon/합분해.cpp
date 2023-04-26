#include <iostream>
using namespace std;
int arr[201][201];
int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        arr[1][i] = i;  // 처음 열 i 로 세팅
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j==1){
                arr[i][j]=1;
                continue;
            }
            arr[i][j]= (arr[i-1][j]+arr[i][j-1])%1000000000;
        }
    }
    cout<<arr[n][k];
}