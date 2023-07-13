#include<iostream>
#include<vector>

using namespace std;
int arr[101][100001];

int main() {
    int n, k;
    vector<pair<int, int>> vec;
    cin >> n >> k;
    vec.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        vec.push_back({w, v});
    }
    for (int i = 1; i < vec.size(); i++) {
        for (int j = 1; j <= k; j++) {
            int weight = vec[i].first;
            int value = vec[i].second;
            if (j >= weight) {
                arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - weight] + value);
            } else arr[i][j] = arr[i - 1][j];
        }
    }
    cout << arr[n][k];
}