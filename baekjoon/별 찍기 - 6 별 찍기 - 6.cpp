#include<iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << ' ';
        }
        for (int j = i; j < 2 * n - 1 - i; j++) {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}