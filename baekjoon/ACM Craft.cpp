#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;
int t, n, k, x, y;
int main() {
    cin >> t;
    while (t--) {
        queue<int> q;
        vector<int> vec[MAX];
        int d[MAX] = {0};
        int indegree[MAX] = {0};
        int result[MAX]={0};
        int cnt = 0;
        int w;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
        }

        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            vec[x].push_back(y);
            indegree[y]++;
        }
        cin>>w;
        for (int i = 1; i <= n; i++) {
            if (!indegree[i]) {
                q.push(i);
                result[i] = d[i];
            }
        }

        while (!q.empty()) {
            int cur;
            cur = q.front();
            if(cur==w) break;
            q.pop();
            for (auto next : vec[cur]) {
                result[next] = max(result[next], result[cur]+d[next]);
                indegree[next]--;
                if (!indegree[next]) q.push(next);
            }
        }
        cout << result[w] << endl;
    }
}