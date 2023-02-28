#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct point {
    int x;
    int y;
};

int dx[] = {-2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1};
int T, l;
point from, to;

void bfs() {
    int map[301][301]={0,};
    queue<point> que;
    que.push(from);
    map[from.x][from.y] = 1;
    while (!que.empty()) {
        if(map[to.x][to.y]!=0) break;
        point cur = que.front();
        que.pop();
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == 0) {
                    int x = cur.x + dx[j];
                    int y = cur.y + dy[j];
                    if (x >= 0 && x < l && y >= 0 && y < l && map[x][y] == 0) {
                        map[x][y] = map[cur.x][cur.y] + 1;
                        point tmp;
                        tmp.x = x;
                        tmp.y = y;
                        que.push(tmp);
                    }
                } 
                else {
                    int x = cur.x + dx[j] * (-1);
                    int y = cur.y + dy[j] * (-1);
                    if (x >= 0 && x < l && y >= 0 && y < l && map[x][y] == 0) {
                        map[x][y] = map[cur.x][cur.y] + 1;
                        point tmp;
                        tmp.x = x;
                        tmp.y = y;
                        que.push(tmp);
                    }
                }
            }
        }
    }
    cout<<map[to.x][to.y]-1<<'\n';
}

int main() {
    int i, j;
    cin >> T;
    while (T--) {
        cin >> l;
        cin >> from.x >> from.y;
        cin >> to.x >> to.y;
        bfs();
    }
}
