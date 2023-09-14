#include<iostream>

using namespace std;

int main() {
    int h, w, n;
    int t;
    cin >> t;
    while (t--) {
        int fr = 0, bk = 1;
        int h, w, n;
        cin >> h >> w >> n;
        while (n > h) {
            n -= h;
            bk++;
        }
        fr = n;
        if (bk >= 10) {
            cout << fr << bk;
        } else {
            cout << fr << 0 << bk;
        }
        cout << '\n';
    }
}