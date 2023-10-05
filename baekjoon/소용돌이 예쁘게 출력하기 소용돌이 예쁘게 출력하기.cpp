#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int map[50][5];
int r1, c1, r2, c2;

void makeMap() {
    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, -1, 0, 1};
    int offset = 0;
    int num = 1;
    int cnt = 0;
    int x = 0;
    int y = 0;
    while (1) {
        if (-offset <= x && x <= offset && -offset <= y && y <= offset) {
            if (r1 <= y && y <= r2 && c1 <= x && x <= c2) {
                map[y - r1][x - c1] = num;
                cnt++;
                if (cnt == (r2 - r1 + 1) * (c2 - c1 + 1)) return;
            }
            num++;
        }
        int dir = 0;

        while (dir < 4) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (-offset <= nx && nx <= offset && -offset <= ny && ny <= offset) {
                if (r1 <= ny && ny <= r2 && c1 <= nx && nx <= c2) {
                    map[ny - r1][nx - c1] = num;
                    cnt++;
                    if (cnt == (r2 - r1 + 1) * (c2 - c1 + 1)) return;
                }
                x = nx;
                y = ny;
                num++;
            } else {
                dir++;
            }
        }
        offset++;
        x++;
    }
}

int findDigit() {
    int maxNum = -1;
    for (int i = 0; i <= r2 - r1; i++) {
        for (int j = 0; j <= c2 - c1; j++) {
            maxNum = max(maxNum, map[i][j]);
        }
    }
    return to_string(maxNum).length();
}

void printSolution() {
    int digit = findDigit();
    for (int i = 0; i <= r2 - r1; i++) {
        for (int j = 0; j <= c2 - c1; j++) {
            int size = to_string(map[i][j]).length();
            for (int k = 0; k < digit - size; k++) {
                cout << " ";
            }
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> r1 >> c1 >> r2 >> c2;
    makeMap();
    printSolution();
}