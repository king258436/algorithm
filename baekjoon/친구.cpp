#include <iostream>
#include <string.h>
using namespace std;

struct st {
    char c;
    bool check;
};
bool visited[51];
st str[51][51];
int n;
int result, sum;
void dp(int depth, int cnt, int idx) {
    int i, j;
    for (i = depth; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == i) continue;
            if (str[i][j].check && cnt == 0) {
                if(!visited[j]){
                    visited[j]=true;
                    sum++;
                }
                dp(j, cnt + 1, i);
            }
            if (str[i][j].check && cnt > 0) {
                if (!visited[j] && j != idx) {
                    visited[j] = true;
                    sum++;
                }
            }
        }
        if (cnt > 0) break;
        if (result < sum) result = sum;
        sum = 0;
        memset(visited, 0, sizeof(bool)*n);
    }
}

int main() {
    int i, j;
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> str[i][j].c;
            if (str[i][j].c == 'Y') str[i][j].check = true;
        }
    }
    dp(0, 0, -1);
    cout << result;
}
