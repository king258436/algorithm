#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n;
string s1, s2;
int dp[5001][5001];

int main() {
    cin >> n >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    int res = 0;
    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    res = dp[s1.size() - 1][s2.size() - 1];
    cout << n - res;
}