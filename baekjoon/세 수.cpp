#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int a,b,c,result;
    scanf("%d %d %d",&a,&b,&c);
    if(a>=b && a>=c){//a가 MAX
        if(b>c) result=b;
        else result=c;
    }
    else if(b>=a &&b>=c){//b가 MAX
        if(a>c) result=a;
        else result=c;
    }
    else{//c가 MAX
        if(a>b) result=a;
        else result=b;
    }
    printf("%d\n",result);
}