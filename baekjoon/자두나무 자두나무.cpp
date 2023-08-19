#include<iostream>
#include<cstring>

using namespace std;
int t, w;
int plum[1001];
int dp[3][31][1001];

void print_test() {
    for (int pos = 1; pos <= 2; pos++) {
        for (int cnt = 0; cnt <= w; cnt++) {
            for (int time = 0; time <= t; time++) {
                cout << dp[pos][cnt][time] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}

int main() {
    cin >> t >> w;
    for (int i = 1; i <= t; i++) {
        cin >> plum[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[1][w][0] = 0;
    for (int time = 0; time < t; time++) {
        for (int cnt = 0; cnt <= w; cnt++) {
            for (int pos = 1; pos <= 2; pos++) {
                if (dp[pos][cnt][time] >= 0) {
                    int next_pos = plum[time + 1];
                    if (pos == next_pos) {
                        dp[pos][cnt][time + 1] = dp[pos][cnt][time] + 1;
                    } else {
                        if (cnt != 0) {
                            dp[next_pos][cnt - 1][time + 1] = max(dp[next_pos][cnt - 1][time + 1],
                                                                  dp[pos][cnt][time] + 1);
                        }
                        dp[pos][cnt][time + 1] = dp[pos][cnt][time];
                    }
                }
            }
        }
    }
    int result = 0;
    for (int pos = 1; pos <= 2; pos++) {
        for (int cnt = 0; cnt <= w; cnt++) {
            result = max(result, dp[pos][cnt][t]);
        }
    }
//    print_test();
    cout << result;
}