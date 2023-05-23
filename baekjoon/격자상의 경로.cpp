#include <iostream>
using namespace std;
int before[20][20];
int after[20][20];
int main() {
    int n, m;
    int c;
    cin >> n >> m >> c;
    int c_c = 0, c_r = 0;
    int copy = c;
    if (c == 0) {
        for (int i = 0; i < n; i++) {
            before[i][0] = 1;
        }
        for (int i = 0; i < m; i++) {
            before[0][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                before[i][j] = before[i - 1][j] + before[i][j - 1];
            }
        }
        cout<<before[n-1][m-1];
        return 0;
    }
    while (1) {
        if (copy > m) {
            copy -= m;
            c_c++;
        } else {
            c_r = copy;
            c_r--;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        before[i][0] = 1;
    }
    for (int i = 0; i < m; i++) {
        before[0][i] = 1;
    }
    for (int i = 1; i <= c_c; i++) {
        for (int j = 1; j <= c_r; j++) {
            before[i][j] = before[i - 1][j] + before[i][j - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        after[i][0] = before[c_c][c_r];
    }
    for (int i = 0; i < m; i++) {
        after[0][i] = before[c_c][c_r];
    }
    for (int i = 1; i <= n - c_c; i++) {
        for (int j = 1; j <= m - c_r; j++) {
            after[i][j] = after[i - 1][j] + after[i][j - 1];
        }
    }
    cout << after[n - c_c - 1][m - c_r - 1];
}