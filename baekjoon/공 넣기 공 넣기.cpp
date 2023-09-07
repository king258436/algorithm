#include<iostream>

using namespace std;
int arr[101];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int st, ed, num;
        cin >> st >> ed >> num;
        for (int j = st; j <= ed; j++) {
            arr[j] = num;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
}