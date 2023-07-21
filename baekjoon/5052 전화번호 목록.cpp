#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool compare(string a, string b) {
    //a가 왼쪽이므로 더 길이가 작아야함.
    if (a.size() >= b.size()) return false;
    else {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        bool flag = false;
        cin >> n;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            v.push_back(temp);
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < n; i++) {
            if (compare(v[i - 1], v[i])) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}