#include <stdio.h>

int arr[101];
int visited[101];
int queue[10000];
int front=-1;
int rear=-1;
int cur;

void enQ(int nIdx){
    rear = (rear+1)%10000;
    queue[rear]=nIdx;
}

int deQ(){
    front= (front+1)%10000;
    return queue[front];
}

void BFS(){
    int temp;
    enQ(1);
    visited[1]=1;
    while(front<rear){
        cur=deQ();
        if(arr[cur]!=0){
            temp=cur;
            cur=arr[cur];
            visited[cur]=visited[temp];
        }
        for(int i=1;i<=6;i++){
            if(visited[cur+i]==0){
                enQ(cur+i);
                visited[cur+i]=visited[cur]+1;
            }
        }
        if(visited[100]!=0) break;
    }
}

int main(){
    int n,m;
    int x,y;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n+m;i++){
        scanf("%d %d",&x,&y);
        arr[x]=y;
    }
    BFS();
    printf("%d",visited[100]-1);
    return 0;

}