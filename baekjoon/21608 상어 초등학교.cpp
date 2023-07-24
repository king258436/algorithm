#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct student {
    int my_num;
    int like_friend[4];
};
struct priority {
    int like_friend_cnt;
    int empty_position_cnt;
    int row;
    int col;
};

struct po {
    int val;
    int idx;
};
int n;
student arr[400];
po position[20][20];
bool visited[20][20];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool compare(priority a, priority b) {
    if (a.like_friend_cnt == b.like_friend_cnt) {
        if (a.empty_position_cnt == b.empty_position_cnt) {
            if (a.row == b.row) {
                return a.col < b.col;
            } else {
                return a.row < b.row;
            }
        } else {
            return a.empty_position_cnt > b.empty_position_cnt;
        }
    } else {
        return a.like_friend_cnt > b.like_friend_cnt;
    }
}

void comp_friend(int num_idx) {
    vector<priority> vec;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int friend_cnt = 0;
            int empty_cnt = 0;
            if (visited[i][j]) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];
                if (nx >= n || nx < 0 || ny >= n || ny < 0) {
                    continue;
                }
                if (position[ny][nx].val == 0) {
                    empty_cnt++;
                } else {
                    for (int l = 0; l < 4; l++) {
                        if (position[ny][nx].val == arr[num_idx].like_friend[l]) {
                            friend_cnt++;
                        }
                    }
                }
            }
            vec.push_back({friend_cnt, empty_cnt, i, j});
        }
    }
    sort(vec.begin(), vec.end(), compare);
    priority check = vec[0];
    position[check.row][check.col].val = arr[num_idx].my_num;
    position[check.row][check.col].idx = num_idx;
    visited[check.row][check.col] = true;
}

int main() {
    cin >> n;
    int num, like;
    for (int i = 0; i < n * n; i++) {
        cin >> arr[i].my_num;
        for (int j = 0; j < 4; j++) {
            cin >> arr[i].like_friend[j];
        }
        comp_friend(i);
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << position[i][j].val << ' ';
//        }
//        cout << '\n';
//    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int point = 0;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (ny >= n || nx >= n || ny < 0 || nx < 0) {
                    continue;
                }
                for (int l = 0; l < 4; l++) {
                    if (position[ny][nx].val == arr[position[i][j].idx].like_friend[l]) {
                        point++;
                    }
                }
            }
            if (point == 0) {
                result += point;
            } else if (point == 1) {
                result += point;
            } else if (point == 2) {
                result += 10;
            } else if (point == 3) {
                result += 100;
            } else {
                result += 1000;
            }
        }
    }
    cout << result;
}