#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char nlist[500000][21], mlist[500000][21];

int compare(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main()
{
    int n, m, cnt = 0;
    int i, j;
    int mid, left, right;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        scanf("%s", nlist[i]);
    } // n개만큼 nlist 에 집어넣음.

    qsort(nlist, n, 21, compare);

    left = 0;
    right = n - 1;

    for (i = 0; i < m; i++)
    {
        left = 0;
        right = n - 1;
        scanf("%s", mlist[cnt]);
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (strcmp(mlist[cnt], nlist[mid]) == 0)
            {
                cnt++;
                continue;
            }
            else
            {
                if (strcmp(mlist[cnt], nlist[mid]) < 0)
                {
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
        }
    }

    printf("%d", cnt);

    qsort(mlist, cnt, 21, compare);

    for (i = 0; i < cnt; i++)
    {
        printf("\n%s", mlist[i]);
    }
    return 0;
}