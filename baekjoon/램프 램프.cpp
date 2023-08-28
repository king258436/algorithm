#include<iostream>
#include<string>
#include<map>

using namespace std;
struct Map_info {
    int cnt;
    int zero_cnt;
};
int n, m;
int k;
map<string, Map_info> lamp;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (lamp.find(str) == lamp.end()) {// 처음 입력된 문자열이라면,
            int zero_cnt = 0;
            for (auto a: str) {
                if (a == '0') {
                    zero_cnt++;
                }
            }
            lamp.insert({str, {1, zero_cnt}});
        } else {// 이미 있을때,
            lamp[str].cnt++;
        }
    }
    cin >> k;
    int result = 0;
    for (auto cur: lamp) {
        if (cur.second.zero_cnt <= k && cur.second.zero_cnt % 2 == k % 2) {
            result = max(result, cur.second.cnt);
        }
    }
    cout << result;
}