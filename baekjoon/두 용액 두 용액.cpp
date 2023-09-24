#include<iostream>
#include <algorithm>
#include<cmath>
#include<vector>
using namespace std;

vector<int> vec;
int arr[2];
int result=2e9;

bool comp(int a, int b){
    int abs_a=abs(a);
    int abs_b=abs(b);
    return abs_b>abs_a;
}

void solve(){
    int sum=0;
    for(int i=0;i<vec.size()-1;i++){
        sum = vec[i]+vec[i+1];
        if(abs(sum)<abs(result)){
            result= sum;
            arr[0]=min(vec[i],vec[i+1]);
            arr[1]=max(vec[i],vec[i+1]);
        }
    }
}

void test_print(){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<' ';
    }
}

int main(){

    int n;
    cin>>n;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        vec.push_back(num);
    }
    sort(vec.begin(),vec.end(), comp);
    solve();
//    test_print();
    cout<<arr[0]<<' '<<arr[1];
}