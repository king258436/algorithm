#include<iostream>
#include<cmath>
using namespace std;
int visited_a[11];
int visited_b[11];

int main(){
    int a,b;
    int c=0;
    cin>>a>>b;
    int r;
    int flag=0;
    while(a){
        for(int i=0;i<11;i++){
            r=pow(2,i);
            if(a<r){
                visited_a[i-1]=1;
                a-=pow(2,i-1);
                break;
            }
        }
    }

    while(b){
        for(int i=0;i<11;i++){
            r=pow(2,i);
            if(b<r){
                visited_b[i-1]=1;
                b-=pow(2,i-1);
                break;
            }
        }
    }
    for(int i=0;i<10;i++){
        if(visited_a[i]^visited_b[i]) c+=pow(2,i);
    }
    cout<< c;
}