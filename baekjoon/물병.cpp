#include <iostream>

using namespace std;

int main() {
    int n, k;
    int result = 0;
    cin >> n >> k;
    if (k >= n) {
        cout << 0;
    } 
    else {
        while (1) {
            int cnt = 0;
            int tmp = n;
            while (tmp > 0) {
                if (tmp % 2 == 1) {
                    tmp /= 2;
                    cnt++;
                } else {
                    tmp /= 2;
                }
            }
            if (cnt <= k)
                break;
            else {
                n++;
                result++;
            }
        }
        cout << result;
    }
}