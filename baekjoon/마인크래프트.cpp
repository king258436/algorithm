#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, b;
    int **arr;
    int i, j, k;
    int time = 0, high = 0, lowtime = 128000000, result_high, inventory;

    scanf("%d %d %d", &n, &m, &b);

    arr = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int) * m);
    } // arr[n][m]동적할당.

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    while (high < 257)
    {
        inventory=b;
        time = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (high < arr[i][j])
                {                                   //부수기
                    time += (arr[i][j] - high) * 2; //부수는 건 2초.
                    inventory += (arr[i][j] - high);        //인벤토리에 부순 블럭만큼 블럭저장.
                }
                else
                {                               //쌓기
                    time += (high - arr[i][j]); //쌓는건 1초.
                    inventory -= (high - arr[i][j]);    //쌓은 블럭 갯수는 인벤토리 에서 제거.
                }
            }
        }
        if (inventory < 0)
        {
            break;
        }
        if (time < lowtime)
        {
            lowtime = time;
            result_high = high;
        }
        else if (time == lowtime)
        {
            result_high = result_high > high ? result_high : high;
        }
        high++;
    }
    printf("%d %d", lowtime, result_high);
    free(arr);
    return 0;
}