#include <iostream>
#include <queue>
#include <vector>
#define MAX 101
using namespace std;
int score[MAX][MAX];
int indegree[MAX];
int n,m,k,y,x;
vector<pair<int,int> > vec[MAX];
queue <int> q;

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y>>k;
        vec[y].push_back(make_pair(x,k));
        indegree[x]++;
    }
    for(int i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(i);
            score[i][i]=1;
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto next: vec[cur]){
            for(int i=1;i<=n;i++){
                score[next.first][i]+=score[cur][i]*next.second;
            }
            indegree[next.first]--;
            if(indegree[next.first]==0){
                q.push(next.first);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(score[n][i]) cout<<i<<' '<<score[n][i]<<endl;
    }
}