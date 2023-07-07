#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string a, b;
int dp[1001][1001];

int main() {
    string temp1, temp2;
    cin >> temp1 >> temp2;
    a = ' ' + temp1;
    b = ' ' + temp2;

    for (int i = 1; i < a.size(); i++) {
        for (int j = 1; j < b.size(); j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int row = a.size() - 1;
    int col = b.size() - 1;
    string res;
    while (dp[row][col]) {
        if (dp[row - 1][col] == dp[row][col]) {
            row--;
        } else if (dp[row][col - 1] == dp[row][col]) {
            col--;
        } else {
            res.push_back(a[row]);
            row--, col--;
        }
    }
    cout << dp[a.size() - 1][b.size() - 1] << "\n";
    if (res.size() > 0) {
        reverse(res.begin(), res.end());
        cout << res << "\n";
    }
    return 0;

}