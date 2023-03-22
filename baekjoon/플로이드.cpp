#include <algorithm>
#include <iostream>
using namespace std;

int arr[105][105];
int INF = 2e8;
int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = INF;
            arr[j][i] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, val;
        cin >> a >> b >> val;
        arr[a - 1][b - 1] = min(arr[a - 1][b - 1], val);
    }

    for (int i = 0; i < n; i++) arr[i][i] = 0;

    for (int k = 0; k < n; k++) {
        for (int s = 0; s < n; s++) {
            for (int t = 0; t < n; t++) {
                arr[s][t] = min(arr[s][t], arr[s][k] + arr[k][t]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] >= INF)
                cout << "0 ";
            else
                cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}