#include<iostream>
#include<queue>
#include<set>

using namespace std;
set<long long> st;
int s, t;
string result;

bool bfs() {
    bool flag = false;
    queue<pair<long long, string>> que;
    que.push({s, ""});
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        if (cur.first == t) {
            flag = true;
            result = cur.second;
            break;
        }
        for (int i = 0; i < 4; i++) {
            long long next;
            string next_s = cur.second;
            if (i == 0) {
                next = cur.first * cur.first;
                next_s += '*';
            } else if (i == 1) {
                next = cur.first + cur.first;
                next_s += '+';
            } else if (i == 2) {
                next = cur.first - cur.first;
                next_s += '-';
            } else if (i == 3 && cur.first != 0) {
                next = cur.first / cur.first;
                next_s += '/';
            }
            if (next > 1000000000) {
                continue;
            }
            if (st.find(next) == st.end()) {// visited 하지않음.
                que.push({next, next_s});
                st.insert(next);
            }
        }
    }
    if (flag) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> s >> t;
    if (s == t) {
        cout << '0';
    } else {
        if (bfs()) {
            cout << result;
        } else {
            cout << -1;
        }
    }
    return 0;

}