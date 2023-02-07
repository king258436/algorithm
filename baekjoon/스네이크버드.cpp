#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,l;
    cin>>n>>l;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(l>=arr[i]){
            l++;
        }
        else break;
    }
    cout<<l;

}