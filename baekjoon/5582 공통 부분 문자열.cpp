#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string s1, s2;
int res;
int dp[4001][4001];

int main() {
    string temp1, temp2;
    cin >> temp1 >> temp2;
    s1 = ' ' + temp1;
    s2 = ' ' + temp2;
    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
        }
    }
    cout << res;
}