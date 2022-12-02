#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i;
    long long sum=0,left=1,right,mid;
    int cut_max=0;
    int *len_list;

    scanf("%d %d", &k, &n);

    len_list = (int *)malloc(sizeof(int) * k);

    for (i = 0; i < k; i++)
    {
        scanf("%d", &len_list[i]);
    }

    for (i = 0, right = 0; i < k; i++)
    {
        if (len_list[i] > right)
            right = len_list[i];
    } // left =0, right = 랜선중 가장 큰값.

    while (left <= right)
    {
        mid = (left + right) / 2;

        for (i = 0,sum =0; i < k; i++)
        {
            sum += len_list[i] / mid;
        }

        if (sum < n)
            right = mid - 1; // sum이 n 보다 작으면 sum을 키워줘야하니까 right를 좀 더 작게 설정(나누니까)
        else
        {
            if (cut_max < mid)
                cut_max = mid;
            left = mid + 1; // 혹시 더 큰 최대길이를 찾을 수 있으니까 최대길이 설정해도 한번더 이분탐색.
        }                   
    }
    printf("%d", cut_max);
    free(len_list);
    return 0;
}