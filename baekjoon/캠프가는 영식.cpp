#include <stdio.h>

int main()
{
    int N,T,sum,a=0;
    long long int min=1000000;
    scanf("%d %d",&N,&T);
    for(int i=1;i<=N;i++)
    {
        int S,I,C;
        scanf("%d %d %d",&S,&I,&C);
        sum=S;
        for(int j=0;j<C;j++)
        {
            sum=S+j*I;
            if(sum>=T)
            {
                min=(min>sum-T)?sum-T:min;
                break;
            }
            else if(T>S+(C-1)*I)
            {
                a=a-1;
                break;
            }
        }
    }
    if(a==-N)
        printf("-1");
    else
        printf("%lld",min);
}