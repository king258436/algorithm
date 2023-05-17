#include <iostream>
using namespace std;

int arr[10001];
int i;

void DandQ(int start, int end){
    if(start>=end) return;
    for(i=start+1;i<end;i++){
        if(arr[start]<arr[i]) break;
    }
    DandQ(start+1,i);
    DandQ(i,end);

    cout<< arr[start]<<endl;
    return;
}

int main(){
    int a;
    int idx=0;
    while(cin>>a){
        arr[idx++]=a;
    }
    DandQ(0,idx);
}