#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int m, n, k, t;
int lis[200000];
priority_queue<pair<int, pair<int, int>>> pq;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        for (int j = k - 1; j >= 0; j--) {
            scanf("%d", &t); pq.push(make_pair(-t, make_pair(i, j)));
        }
    }
    while (!pq.empty()) {
        pair<int, pair<int, int>> tmp = pq.top(); pq.pop();
        if (lis[tmp.second.first]++ != tmp.second.second) {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}
