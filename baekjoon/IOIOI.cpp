#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m;
    char *s;
    char *Pn;
    int i,cnt=0,result=0;

    scanf("%d %d",&n,&m);
    s=(char*)malloc(sizeof(char)*m+1);

    scanf("%s",s);
    
    for(i=0;i<m;i++){
        if(s[i]=='I'){
            i++;
            if(s[i]=='O'&&s[i+1]=='I') cnt++;
            else{
                cnt=0;
                i--;
            }
        }
        if(cnt==n){
            result++;
            cnt--;
        }
    }
    printf("%d",result);

}