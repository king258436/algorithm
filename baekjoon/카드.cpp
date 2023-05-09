#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a;
    map<long long, int> ma;

    for (int i = 0; i < n; i++) {
        cin >> a;
        ma[a]++;
    }
    int maxcnt = 0;
    long long res;
    for (auto &m : ma) {
        if (m.second > maxcnt) {
            maxcnt = m.second;
            res = m.first;
        }
    }
    cout << res;
}