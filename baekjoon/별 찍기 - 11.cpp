#include <iostream>
using namespace std;
char map[3072][6144];
void recur(int x, int y, int n) {
    if (n == 3) {
        map[x][y] = '*';
        map[x + 1][y - 1] = '*';
        map[x + 1][y + 1] = '*';
        for (int i = -2; i <= 2; i++) {
            map[x + 2][y+i] = '*';
        }
        return;
    } else {
        recur(x, y, n / 2);
        recur(x + n / 2, y - n / 2, n / 2);
        recur(x + n / 2, y + n / 2, n / 2);
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            map[i][j] = ' ';
        }
    }

    recur(0, n - 1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << map[i][j];
        }
        cout << "\n";
    }
}