#include<iostream>
#include<vector>

#define INF 1e9
using namespace std;
int arr[401][401];
int V, E;

int main() {
    cin >> V >> E;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            arr[i][j] = 1e9;
        }
    }
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = c;
    }

    for (int k = 1; k <= V; k++) {// k는 지나가는 정점
        for (int i = 1; i <= V; i++) {// i는 출발 정점
            for (int j = 1; j <= V; j++) { // j는 도착 정점
                if (arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }
    int result = INF;
    for (int i = 1; i <= V; i++) {
        result = min(result, arr[i][i]);
    }

    if (result == INF) cout << -1;
    else cout << result;
}