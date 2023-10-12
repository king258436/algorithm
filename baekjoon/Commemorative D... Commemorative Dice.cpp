#include<iostream>

using namespace std;
int arr[2][6];

int gcd(int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int n;
    while (b) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }
    int cnt = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (arr[0][i] > arr[1][j]) {
                cnt++;
            }
        }
    }
    int GCD = gcd(cnt, 36);
    cout << cnt / GCD << '/' << 36 / GCD;

}