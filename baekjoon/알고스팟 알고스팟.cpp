#include<iostream>
#include<string>
#include<queue>
 
#define endl "\n"
#define MAX 100
using namespace std;
 
int N, M, Answer;
int MAP[MAX][MAX];
int Dist[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Input()
{
    Answer = 987654321;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        string Inp;
        cin >> Inp;
        for (int j = 0; j < Inp.length(); j++)
        {
            MAP[i][j] = Inp[j] - '0';
            Dist[i][j] = 987654321;
        }
    }
}
 
void Print()
{
    cout << "#############################" << endl;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << Dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << "#############################" << endl;
 
}
 
void BFS(int a, int b)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    Dist[a][b] = 0;
 
    while (Q.empty() == 0)
    {
        //Print();
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
            
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
                
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            
            if (MAP[nx][ny] == 1)
            {
                if (Dist[nx][ny] > Dist[x][y] + 1)
                {
                    Dist[nx][ny] = Dist[x][y] + 1;
                    Q.push(make_pair(nx, ny));
                }
            }
            else if (MAP[nx][ny] == 0)
            {
                if (Dist[nx][ny] > Dist[x][y])
                {
                    Dist[nx][ny] = Dist[x][y];
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
 
void Solution()
{
    BFS(0, 0);
    cout << Dist[M-1][N-1] << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}