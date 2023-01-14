#include <stdio.h>
#include <string.h>

int main(){
    int n,x,i;
    int Bsum=0,Ssum=0,Lsum=0,Psum=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        char s[20];
        int num;
        
        scanf("%s",s);
        scanf("%d",&num);

        if(s[0]=='S'){
            Ssum+=num;
        }
        else if(s[0]=='B'){
            Bsum+=num;
        }
        else if(s[0]=='L'){
            Lsum+=num;
        }
        else Psum+=num;
    }

    if(Ssum==5||Bsum==5||Lsum==5||Psum==5){
        printf("YES");
    }
    else printf("NO");
    return 0;
}