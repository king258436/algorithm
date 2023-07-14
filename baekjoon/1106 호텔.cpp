#include<iostream>
#include<vector>

using namespace std;
int dp[100001];

int main() {
    int c, n;
    vector<pair<int, int>> vec;
    vec.push_back({0, 0});
    cin >> c >> n;
    for (int i = 0; i < n; i++) {
        int co, per;
        cin >> co >> per;
        vec.push_back({co, per});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100001; j++) {
            if (j >= vec[i].first) {
                dp[j] = max(dp[j], dp[j - vec[i].first] + vec[i].second);
            }
        }
    }
    for (int i = 1; i <= 100000; i++) {
        if (dp[i] >= c) {
            cout << i;
            return 0;
        }
    }
}