#include <stdio.h>

int main(){
    int n;
    int i,num=0,flag=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        char s[10];
        int card;
        scanf("%s",s);
        scanf("%d",&card);
        if(flag==0){
            if(num==12) num=1;
            else num++;
        }
        else{
            if(num==1) num=12;
            else num--;
        }
        if(s[0]=='H'&&num!=card){
            if(flag==0) flag=1;
            else flag=0;
            printf("%d NO\n",num);
        }
        else if(s[0]!='H'&&num==card){
            printf("%d YES\n",num);
        }
        else {
            printf("%d NO\n",num);
        }
    }
    return 0;
}