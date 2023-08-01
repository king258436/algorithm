#include<iostream>
#include<algorithm>

#define INF 1e9
using namespace std;
int arr[100][100];
int item[100];
int n, m, r;

void simul() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        cin >> item[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        arr[a - 1][b - 1] = l;
        arr[b - 1][a - 1] = l;
    }
    for (int i = 0; i < n; i++) {
        arr[i][i] = 0;
    }
//    simul();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] <= m) {
                cnt += item[j];
            }
        }
        result = max(cnt, result);
    }
    cout << result << '\n';
//    simul();

}