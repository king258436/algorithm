#include <iostream>

using namespace std;
int n;
int arr[11];
int res[11];
int main(){
    int i,j;
    cin>> n;
    for(i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(i=1;i<=n;i++){
        int cnt=-1;
        for(j=1;j<=n;j++){
            if(res[j]==0)cnt++;
            if(i==n&&res[j]==0) res[j]=i;
            if(cnt==arr[i]){
                res[j]=i;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<< res[i]<<' ';
    }
    return 0;
}