#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int get_distance(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<string> vec;
        int result = 100;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            vec.push_back(str);
        }
        if (n >= 33) {
            cout << 0 << '\n';
            continue;
        } else {
            for (int i = 0; i < n - 2; i++) {
                for (int j = i + 1; j < n - 1; j++) {
                    for (int k = j + 1; k < n; k++) {
                        result = min(get_distance(vec[i], vec[j]) + get_distance(vec[j], vec[k]) +
                                     get_distance(vec[i], vec[k]), result);
                    }
                }
            }
        }
        cout << result << '\n';
    }
}