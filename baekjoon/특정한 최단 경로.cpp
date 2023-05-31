#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int n, e;
int v1, v2;
vector<pair<int, int> > v[801];
int dis[801];
bool flag_v1,flag_v2;
void djstra(int st, int en) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    fill(dis,dis+n+1,200000000);
    pq.push(make_pair(0, st));
    dis[st] = 0;

    while (!pq.empty()) {
        int cn = pq.top().second;
        int cd = pq.top().first;
        pq.pop();
        if(cd>dis[cn]) continue;
        if(cn==en){
            break;
        }
        for(auto next : v[cn]){
            int nn=next.first;
            int nd=next.second+cd;
            if(nd<dis[nn]){
                dis[nn]=nd;
                pq.push(make_pair(nd,nn));
            }
        }
    }
}

int main() {
    cin >> n >> e;
    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;
    int ans,ans1,ans2;
    djstra(1,v1);
    ans1=dis[v1];

    djstra(v1,v2);
    ans1+=dis[v2];
    ans2=dis[v2];

    djstra(v2,n);
    ans1+=dis[n];

    djstra(1,v2);
    ans2+=dis[v2];

    djstra(v1,n);
    ans2+=dis[n];

    ans = min(ans1,ans2);

    if(ans>=200000000) ans=-1;
    cout<< ans;


}