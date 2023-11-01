#include<iostream>

using namespace std;
bool robot[202] = {0};
int conbayer[202];
int n, k;
int cnt;
int start;
int last;
bool flag;

void rotation() {// 벨트가 한번 도는 함수
    if (start == 1) start = 2 * n;
    else start--;

    if (last == 1) last = 2 * n;
    else last--;

    if (robot[last] == true) {
        robot[last] = false;
    }
}

void move_robot() {

    int idx = last;
    for (int i = 1; i < n; i++) {// last에 로봇이있었으면, 내려갔음 따라서 n-1 번까지만 로봇 옮기기
        int next = idx;
        if (idx == 1) idx = 2 * n;
        else idx--;
        if (robot[idx] && conbayer[next] > 0 && !robot[next]) {
            conbayer[next]--;
            if (conbayer[next] == 0) {
                cnt++;
                if (k <= cnt) {
                    flag = true;
                    break;
                }
            }
            robot[idx] = false;
            robot[next] = true;
        }
    }
    robot[last] = false;
}

void put_robot() {
    if (conbayer[start] > 0) {
        conbayer[start]--;
        if (conbayer[start] == 0) {
            cnt++;
            if (k <= cnt) {
                flag = true;
            }
        }
        robot[start] = true;
    }

}

int main() {
    cin >> n >> k;
    start = 1;
    last = n;
    int level = 0;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> conbayer[i];
    }
    while (1) {
        level++;
        rotation();
        move_robot();
        put_robot();
        if (flag) break;
    }
    cout << level;

}