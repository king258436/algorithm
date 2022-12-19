#include <stdio.h>
#include <math.h>

int main(){
    int t,n,m,num,cnt=0,zero_cnt=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        zero_cnt=0;
        scanf("%d %d",&n,&m);
        for(int j=n;j<=m;j++){
            num=j;
            if(j==0){
                zero_cnt++;
                continue;
            }
            while(num>0){
                num/=10;
                cnt++;
            }//몇자리수인지.
            for(int k=0;k<cnt;k++){
                if((j/(int)pow(10,(double)k)%10)==0) zero_cnt++;
            }
            cnt=0;
        }
        printf("%d\n",zero_cnt);
    }
    return 0;
}