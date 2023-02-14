#include <iostream>

using namespace std;

int arr[51][51];
int cnt;
int dr[] = {-1, 0, 1, 0};  // 북 동 남 서
int dc[] = {0, 1, 0, -1};
int main() {  // 0은 청소 되지않은 빈칸, 1벽, 2청소 된 빈칸.
    int n, m;
    int r, c, d;
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    while (1) {
        int flag = 1;
        if (arr[r][c] == 0) {  // 지금 위치가 청소 가능한경우
            cnt++;
            arr[r][c] = 2;
        }
        for (int i = 0; i < 4; i++) {
            int nr, nc;
            if (r + dr[i] >= 0 && c + dc[i] >= 0 && r + dr[i] < n && c + dc[i] < m) {
                nr = r + dr[i];
                nc = c + dc[i];

                if (arr[nr][nc] == 0) {
                    flag = 0;  // 주변 4방위중 청소 가능한 곳이있을때.
                    break;
                }
            }
        }
        if (flag == 1) {    // 청소 할곳 없을때
            r = r - dr[d];  // 후진
            c = c - dc[d];

            if (r >= 0 && r < n && c >= 0 && c < m && arr[r][c] != 1) {  // 후진 한곳이 벽이 아니라면
                continue;                                                // 다시 1번으로
            } 
            else
                break;           // 후진 한곳이 벽이면 멈춤
        } else if (flag == 0) {  // 청소 할 곳 있을때
            while (1) {
                if (d == 0)
                    d = 3;
                else
                    d = d - 1;
                int nr, nc;
                nr = r + dr[d];
                nc = c + dc[d];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && arr[nr][nc] == 0) {
                    r = nr;
                    c = nc;
                    break;
                }
            }
        }
    }
    cout<<cnt;
}