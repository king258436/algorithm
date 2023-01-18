#include <stdio.h>
#include <string.h>

#define max 1000000

int k;
int visited[max];
int cnt[max];

typedef struct _Q {
    int front;
    int rear;
    int data[max];
} queue;

void bfs(int x) {
    queue q;
    memset(q.data,0,sizeof(int)*max);
    int pop;
    q.front = -1;
    q.rear = -1;
    q.data[++q.rear] = x;  // 인큐
    visited[x] = 1;
    while (q.front < q.rear) {
        pop = q.data[++q.front];
        if (visited[pop + 1] == 0&&pop+1<=100000) {
            q.data[++q.rear] = pop + 1;
            cnt[pop + 1] = cnt[pop] + 1;
            visited[pop+1]=1;
        }
        if (visited[pop - 1] == 0&&pop-1>=0) {
            q.data[++q.rear] = pop - 1;
            cnt[pop - 1] = cnt[pop] + 1;
            visited[pop-1]=1;
        }
        if (visited[pop * 2] == 0&&pop*2<=100000) {
            q.data[++q.rear] = pop * 2;
            cnt[pop * 2] = cnt[pop] + 1;
            visited[pop*2]=1;
        }
        if (cnt[k]!=0) return;
    }
}

int main() {
    int x;
    scanf("%d %d", &x, &k);
    bfs(x);
    printf("%d",cnt[k]);
    return 0;
}