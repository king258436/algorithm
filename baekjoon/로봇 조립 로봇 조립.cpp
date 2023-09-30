#include<iostream>
#define MAX 1000001
using namespace std;
int parent[MAX];
int parts[MAX];
int getParent(int x){
    if(parent[x]==x){
        return x;
    }
    return getParent(parent[x]);
}

void unionParent(int a,int b){
    a= getParent(a);
    b= getParent(b);
    if(a<b){
        parent[b]=a;
        parts[a]+=parts[b];
        parts[b]=0;
    }
    else{
        parent[a]=b;
        parts[b]+=parts[a];
        parts[a]=0;
    }
}

bool findParent(int a,int b){
    a= getParent(a);
    b= getParent(b);
    if(a==b){
        return 1;
    }
    else return 0;
}
void init(){
    for(int i=0;i<MAX;i++){
        parent[i]=i;
        parts[i]=1;
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    init();
    int n;
    cin>> n;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='I'){
            int a,b;
            cin>>a>>b;
            if(!findParent(a,b)){
                unionParent(a, b);
            }
        }
        else if(c=='Q'){
            int a;
            cin>>a;
            cout<<parts[getParent(a)]<<'\n';
        }
    }
}