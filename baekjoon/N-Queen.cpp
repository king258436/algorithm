#include <iostream>
using namespace std;

bool isused1[33];
bool isused2[33];
bool isused3[33];
int n;
int cnt;

void dfs(int cur) {
    if (cur == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isused1[i] || isused2[cur + i] || isused3[cur-i+n-1]) continue;
        isused1[i] = true;
        isused2[cur + i] = true;
        isused3[cur-i+n-1] = true;
        dfs(cur + 1);
        isused1[i] = false;
        isused2[cur + i] = false;
        isused3[cur-i+n-1] = false;
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << cnt;
}