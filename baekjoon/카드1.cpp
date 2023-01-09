#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node * next;
}Node;

typedef struct _q{
    Node *front;
    Node *rear;
}Queue;

void Init(Queue *q){
    q->front=NULL;
    q->rear = NULL;
}

void enqueue(Queue *q,int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    if(q->front==NULL){
        q->front=newNode;
        q->rear=newNode;
    }
    else{
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

int dequeue(Queue *q){
    Node *rpos = q->front;
    int rdata = q->front->data;
    q->front=q->front->next;
    free(rpos);
    return rdata;
}

int main(){
    int n,i,temp,cnt=0;
    Queue q;
    Init(&q);

    scanf("%d",&n);

    for(i=0;i<n;i++){
        enqueue(&q,i+1);
    }

    while(1){
        temp=dequeue(&q);
        cnt++;
        printf("%d ",temp);
        if(cnt==n) break;
        temp=dequeue(&q);
        enqueue(&q,temp);
    }
    return 0;
}