#include <stdio.h>

typedef struct cn
{
    int cnt_0;
    int cnt_1;
} cnt;

cnt fibo(int n)
{
    cnt fibo_cnt[40];

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            fibo_cnt[i].cnt_0 = 1;
            fibo_cnt[i].cnt_1=0;
        }
        else if (i == 1)
        {
            fibo_cnt[i].cnt_0 = 0;
            fibo_cnt[i].cnt_1=1;
        }
        else
        {
            fibo_cnt[i].cnt_0 = fibo_cnt[i - 1].cnt_0 + fibo_cnt[i - 2].cnt_0;
            fibo_cnt[i].cnt_1 = fibo_cnt[i - 1].cnt_1 + fibo_cnt[i - 2].cnt_1;
        }
    }
    return fibo_cnt[n];
}

int main()
{
    int TestCase, n;
    scanf("%d", &TestCase);
    cnt result;
    for (int i = 0; i < TestCase; i++)
    {
        scanf("%d", &n);
        result = fibo(n);
        printf("%d %d\n", result.cnt_0, result.cnt_1);
    }
    return 0;
}