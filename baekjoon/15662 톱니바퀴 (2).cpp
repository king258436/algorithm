#include<iostream>
#include<string>
#include<queue>
#include<cstring>

using namespace std;

struct Que_info {
    int gear_num;
    int rotation_dir;
};

bool visited[1001];
string gear[1001];
int t, k;

void Rotation(int gear_num, int rotation_dir) {
    queue<Que_info> q;
    q.push({gear_num, rotation_dir});
    visited[gear_num] = true;
    while (!q.empty()) {
        Que_info cur = q.front();
        q.pop();
        char right = gear[cur.gear_num][2];
        char left = gear[cur.gear_num][6];
        for (int i = -1; i <= 1; i += 2) {
            int next_gear_num = cur.gear_num + i;
            if (next_gear_num <= 0 || next_gear_num > t) {
                continue;
            }
            if (visited[next_gear_num]) {
                continue;
            }
            char next_right = gear[next_gear_num][2];
            char next_left = gear[next_gear_num][6];
            if (i == -1) {// 다음기어가 왼쪽 이라면, 왼쪽기어의 오른쪽 자극과 현재기어의 왼쪽자극을 비교
                if (next_right == left) {// 같으면 그냥 무시
                    continue;
                } else { // 다르면 다음기어를 현재기어의 회전방향이랑 반대로 돌려야댐 따라서 큐에 집어넣음.
                    q.push({next_gear_num, cur.rotation_dir * -1});
                }
                visited[next_gear_num] = true;
            } else {// 다음기어가 오른쪽이라면, 오른쪽기어의 왼쪽자극과 현재기어의 오른쪽 자극을 비교
                if (next_left == right) {
                    continue;
                } else {
                    q.push({next_gear_num, cur.rotation_dir * -1});
                }
                visited[next_gear_num] = true;
            }

        }
        if (cur.rotation_dir == -1) {
            char temp = gear[cur.gear_num][0];
            gear[cur.gear_num].erase(0, 1);
            gear[cur.gear_num].push_back(temp);
        } else {
            string temp;
            temp.push_back(gear[cur.gear_num][7]);
            gear[cur.gear_num].erase(7, 1);
            gear[cur.gear_num].insert(0, temp);
        }
    }
}

int find_12_s() {
    int cnt = 0;
    for (int i = 1; i <= t; i++) {
        if (gear[i][0] == '1') {
            cnt++;
        }
    }
    return cnt;
}

void simul() {
    for (int i = 1; i <= t; i++) {
        cout << i << ' ' << gear[i] << '\n';
    }
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> gear[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int gear_num, rotation_dir;
        cin >> gear_num >> rotation_dir;
        Rotation(gear_num, rotation_dir);
        memset(visited, 0, sizeof(visited));
    }
    cout << find_12_s();
}