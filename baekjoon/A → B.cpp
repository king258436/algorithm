#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long a;
long long b;
int cnt;
int minv;

void BFS() {
    queue<pair<long long, int> > q;
    q.push(make_pair(a,0));
    while (!q.empty()) {
        pair <long long, int> tmp = q.front();
        q.pop();
        if (tmp.first * 2 <= b)
            q.push(make_pair(tmp.first*2,tmp.second+1));
        if (tmp.first * 10 + 1 <= b)
            q.push(make_pair(tmp.first * 10 + 1,tmp.second+1));
        if (tmp.first == b) {
            cout << tmp.second+1;
            return ;
        }
    }
    cout<<"-1";
}

int main() { 
    cin >> a >> b; 
    BFS();
    return 0;
}