#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

long long Bsearch(int arr[], int len, int target)
{
    long long first = 1;
    long long last = arr[len - 1];
    long long mid, sum = 0, cut_max=0;
    int i;
    while (first <= last)
    {
        mid = (first + last) / 2;

        for (i = 0,sum=0; i < len; i++)
        {
            if(arr[i]-mid>0) sum+=arr[i]-mid;
        }
        if (sum < target)
            last = mid -1;
        else
        {
            if (cut_max < mid){
                cut_max = mid;
            }
            first = mid +1;
        }
    }
    return cut_max;
}

int main()
{
    int n, m;
    int *tree_high;

    scanf("%d %d", &n, &m);

    tree_high = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tree_high[i]);
    }

    qsort(tree_high, n, sizeof(int), compare);

    printf("%lld\n", Bsearch(tree_high, n, m));
    free(tree_high);
    return 0;
}