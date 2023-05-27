#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    bool plus = false;
    for (int i = 1; i <= n; i++) {
        int copy = i,temp = -1;
        bool flag = false;
        if (plus) cnt++;
        plus = false;
        while (copy) {
            if(temp==0 && copy%10==5){
                plus=1;
                break;
            }
            temp = copy%10;
            copy /= 10;
        }
        cnt++;
    }
    cout << cnt;
}