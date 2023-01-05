#include <stdio.h>
#include <string.h>

int main(){
    char s[51];
    int cnt=0,Lcnt=0;
    int i,j;

    scanf("%s",s);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='(') Lcnt++;
        if(Lcnt>0&&s[i]==')') Lcnt--;
        else if(Lcnt==0&&s[i]==')') cnt++;
    }
    cnt= Lcnt +cnt;
    printf("%d",cnt);
}