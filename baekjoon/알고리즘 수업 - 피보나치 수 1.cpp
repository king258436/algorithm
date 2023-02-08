#include <iostream>
#include <vector>
using namespace std;

int dp_cnt;
int rec_cnt;

int fib(int n) {
    if (n == 1 || n == 2){
        rec_cnt++;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

void fibonacci(vector <int> &vec,int n) {
    vec[1]=1;
    vec[2]=1;
    for(int i=3;i<=n;i++){
        vec[i]=vec[i-1]+vec[i-2];
        dp_cnt++;
    }
    return ;
}

int main(){
    int n;
    vector <int> vec(41);
    cin>>n;
    fib(n);
    fibonacci(vec,n);
    cout<<rec_cnt<<" "<<dp_cnt;
}