#include <stdio.h>
#include <string.h>

int S[21];// S[0] 은 버리는걸로.

void rmove(int x){
    S[x]=0;
}

void add(int X){
    S[X]=1;
}

int check(int x){
    if(S[x]==1) return 1;
    else return 0;
}

void toggle(int x){
    if(S[x]==1) S[x]=0;
    else S[x]=1;
}

void all(void){
    for(int i=1;i<21;i++){
        S[i]=1;
    }
}

void empty(void){
    for(int i=1;i<21;i++){
        S[i]=0;
    }
}

int main(){
    int m,x;
    char str[10];
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%s",str);
        if(!strcmp(str,"add")){
            scanf("%d",&x);
            add(x);
        }
        else if(!strcmp(str,"remove")){
            scanf("%d",&x);
            rmove(x);
        }
        else if(!strcmp(str,"check")){
            scanf("%d",&x);
            printf("%d\n",check(x));
        }
        else if(!strcmp(str,"toggle")){
            scanf("%d",&x);
            toggle(x);
        }
        else if(!strcmp(str,"all")){
            all();
        }
        else if(!strcmp(str,"empty")){
            empty();
        }
    }
    return 0;
}