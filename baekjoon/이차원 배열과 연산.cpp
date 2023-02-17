#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int map[101][101];
int cnt[101];
int size_H, size_Y;

int main() {
    int r, c, k;
    int i, j;
    int Y, H;
    int TIME = 0;
    
    cin >> r >> c >> k;
    for (i = 1; i < 4; i++) {
        for (j = 1; j < 4; j++) cin >> map[i][j];
    }
    Y = 3;
    H = 3;
    while (1) {
        if (map[r][c] == k) break;
        if (TIME > 100) {
            TIME = -1;
            break;
        }
        if (H >= Y) {
            for (i = 1; i <= H; i++) {
                vector<pair<int, int> > vec;
                memset(cnt, 0, sizeof(cnt));
                for (j = 1; j <= Y; j++) {
                    cnt[map[i][j]]++;  // 중복된 수 구하기.
                }
                for (j = 1; j <= 100; j++) {                      // 수를 정렬할때 0은 무시한다.//
                    if (cnt[j] != 0) vec.push_back(make_pair(cnt[j], j));  // vec에 개수, 수 저장.//
                }
                sort(vec.begin(), vec.end());            // 정렬 우선순위대로 정렬//
                for (j = 1; j <= Y; j++) map[i][j] = 0;  // 행 또는 열의 크기가 커진곳에는 0으로 채운다.
                int idx = 1;
                for (j = 0; j < vec.size(); j++) {
                    map[i][idx++] = vec[j].second;
                    map[i][idx++] = vec[j].first;
                }
                if (size_Y < idx - 1) size_Y = idx - 1;
            }
            Y = size_Y;
        } else {  // Y>H.
            for (i = 1; i <= Y; i++) {
                vector<pair<int, int> > vec;
                memset(cnt, 0, sizeof(cnt));
                for (j = 1; j <= H; j++) {
                    cnt[map[j][i]]++;
                }
                for (j = 1; j <= 100; j++) {
                    if (cnt[j] != 0) vec.push_back(make_pair(cnt[j], j));
                }
                sort(vec.begin(), vec.end());
                int idx = 1;
                for (j = 1; j <= H; j++) map[j][i] = 0;
                for (j = 0; j < vec.size(); j++) {
                    map[idx++][i] = vec[j].second;
                    map[idx++][i] = vec[j].first;
                }
                if (size_H < idx-1) size_H = idx-1;
            }
            H = size_H;
        }
        TIME++;
    }
    cout << TIME;
    return 0;
}