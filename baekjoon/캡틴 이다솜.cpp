#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
#define MAX 300000

ll dp[MAX + 2];

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 1;; i++) {
		int num = i * (i + 1) * (i+2) / 6;
		if (num > MAX) break;
		v.push_back(num);
	}

	fill(dp, dp + MAX + 1, 1e9);
	for (int i = 0;i < v.size(); i++) dp[v[i]] = 1;
	
	for (int i = 0; i < v.size(); i++) {
		for (int j = v[i]; j <= N; j++) {
			dp[j] = min(dp[j],dp[j - v[i]] + 1);
		}
	}
	cout << dp[N];
}