#include<iostream>

using namespace std;

int Max_dp[3];
int Min_dp[3];

int temp[3];
int temp2[3];

int tri_max(int a, int b, int c) {
    a = max(a, b);
    b = max(b, c);
    return max(a, b);
}

int tri_min(int a, int b, int c) {
    a = min(a, b);
    b = min(b, c);
    return min(a, b);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) {
        cin >> Max_dp[i];
        Min_dp[i] = Max_dp[i];
    }
    n--;
    while (n--) {
        for (int i = 0; i < 3; i++) {
            int num;
            cin >> num;
            if (i == 0) {
                temp[0] = max(Max_dp[0] + num, Max_dp[1] + num);
                temp2[0] = min(Min_dp[0] + num, Min_dp[1] + num);
            } else if (i == 1) {
                temp[1] = tri_max(Max_dp[0] + num, Max_dp[1] + num, Max_dp[2] + num);
                temp2[1] = tri_min(Min_dp[0] + num, Min_dp[1] + num, Min_dp[2] + num);
            } else {
                temp[2] = max(Max_dp[2] + num, Max_dp[1] + num);
                temp2[2] = min(Min_dp[2] + num, Min_dp[1] + num);
            }
        }
        for (int i = 0; i < 3; i++) {
            Max_dp[i] = temp[i];
            Min_dp[i] = temp2[i];
        }
    }
    cout << tri_max(Max_dp[0], Max_dp[1], Max_dp[2]) << ' ' << tri_min(Min_dp[0], Min_dp[1], Min_dp[2]);
}