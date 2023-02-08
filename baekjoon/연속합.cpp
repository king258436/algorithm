#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n),arr(n,0);// arr는 해당 idx 까지의 최대합을 저장, vec은 초기값 저장
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    arr[0]=vec[0];
    int max=arr[0];
    for(int i=1;i<n;i++){
        arr[i]=arr[i-1]+vec[i];
        if(arr[i]<vec[i]) arr[i]=vec[i];
        if(arr[i]>max) max= arr[i];
    }

    cout<<max;
}