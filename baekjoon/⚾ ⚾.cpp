#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
int stats[51][10];
int order[10];
int visited[10];
bool ground[4];
int n;
int result;

void print_test() {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << stats[i][order[j]] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void play() {
    int point = 1;
    int score = 0;
//    vector<int> vec;
    for (int i = 0; i < n; i++) {
        memset(ground, 0, sizeof(ground));
        int out_cnt = 0;
        while (out_cnt < 3) {
            auto player = stats[i][order[point]];
            if (player == 1) {//플레이어가 안타를 쳤을때
                if (ground[3]) {// 3루에 사람있으면 홈으로 들어옴
                    score++;
                }
                ground[3] = ground[2];
                ground[2] = ground[1];
                ground[1] = 1;//안타 친사람 1루로 안착
            } else if (player == 2) {// 플레이어가 2루타를 쳤을때
                for (int j = 2; j <= 3; j++) {
                    if (ground[j]) {
                        score++;
                    }
                }
                ground[3] = ground[1];
                ground[2] = 1;
                ground[1] = 0;
            } else if (player == 3) {
                for (int j = 1; j <= 3; j++) {
                    if (ground[j]) {
                        score++;
                    }
                }
                ground[3] = 1;
                ground[2] = 0;
                ground[1] = 0;
            } else if (player == 4) {
                for (int j = 1; j <= 3; j++) {
                    if (ground[j]) {
                        score++;
                    }
                }
                memset(ground, 0, sizeof(ground));
                score++;
            } else if (player == 0) {// 아웃일때
                out_cnt++;
            }
            point %= 9;
            point++;
        }
//        vec.push_back(score);
    }
    if (score > result) {
        result = score;
//        for (auto a: vec) {
//            cout << a << ' ';
//        }
//        cout << '\n';
//        print_test();
    }
}


void permutation(int cnt) {
    if (cnt == 10) {// play 함수시작
        play();
//        print_test();
    } else {
        for (int i = 1; i < 10; i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            order[i] = cnt;
            permutation(cnt + 1);
            visited[i] = false;
//            print_test();
        }
    }
}

int main() {
    cin >> n;
    for (int y = 0; y < n; y++) {
        for (int x = 1; x < 10; x++) {
            cin >> stats[y][x];
        }
    }
    visited[4] = true;
    order[4] = 1;
    permutation(2);
    cout << result;
}
