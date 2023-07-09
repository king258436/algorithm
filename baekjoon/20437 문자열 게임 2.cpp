#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        int k;
        int resMax = 0;
        int resMin = 1000000;
        vector<int> idx[26];
        cin >> str >> k;
        for (int i = 0; i < str.size(); i++) {
            idx[str[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < idx[i].size(); j++) {
                if (j + k - 1 >= idx[i].size()) break;
                resMin = min(resMin, idx[i][j + k - 1] - idx[i][j] + 1);
                resMax = max(resMax, idx[i][j + k - 1] - idx[i][j] + 1);
            }
        }
        if (resMax == 0 || resMin == 1000000) cout << -1 << "\n";
        else cout << resMin << ' ' << resMax << "\n";
    }
}