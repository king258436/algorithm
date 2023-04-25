#include <iostream>
#include <string>
using namespace std;
int arr[10];
int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        arr[s[i] - '0']++;
    }

    int hap = arr[6]+arr[9];

    if(hap%2==1){
        hap= hap/2+1;
        arr[6]=hap;
        arr[9]=hap;
    }
    else{
        hap= hap/2;
        arr[6]=hap;
        arr[9]=hap;
    }

    int res = 0;
    for (int i = 0; i < 10; i++) {
        if (res < arr[i]) res = arr[i];
    }
    cout << res;
}