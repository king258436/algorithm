#include<iostream>
#include <vector>

using namespace std;
int arr[101][10001];
int mem[101];
int cost[101];
int res = 1e9;

int main() {
    int N, M;
    int sum = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> mem[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        sum += cost[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= cost[i]) {
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - cost[i]] + mem[i]);
                if (arr[i][j] >= M && res > j) res = j;
            } else arr[i][j] = arr[i - 1][j];
        }
    }
    cout << res;
}