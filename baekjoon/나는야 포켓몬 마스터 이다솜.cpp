#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct poketmon
{
    char name[21];
    int num;
} ency;

int compare(const void *first, const void *second)
{
    ency *a = (ency *)first;
    ency *b = (ency *)second; // 구조체 끼리 같이가야 되니깐.
    if (strcmp(a->name, b->name) > 0)
        return 1;
    else
        return -1;
}

int main()
{
    int n, m, i, right, left, mid;
    char temp[21]; // m 입력받을 공간 할당.

    scanf("%d %d", &n, &m);

    ency *list = NULL;    // 그냥 입력받은 그대로의 도감.
    ency *list_st = NULL; // 사전적으로 정렬된 도감.

    list = (ency *)calloc(n, sizeof(ency));
    list_st = (ency *)calloc(n, sizeof(ency)); // 동적할당.

    for (i = 0; i < n; i++)
    {
        scanf("%s", list[i].name);
        list[i].num = i + 1; // list에 도감입력.

        strcpy(list_st[i].name, list[i].name);
        list_st[i].num = i + 1; // list_st 에 도감입력.

    } // 구조체 배열에 포켓몬이름과 도감 번호를 넣어줌.

    qsort(list_st, n, sizeof(ency), compare); // list_st 사전순 정렬.

    for (i = 0; i < m; i++)
    {
        scanf("%s", temp);      // temp 에 찾아야하는 숫자나 이름
        if (atoi(&temp[0]) == 0) // 입력받은 temp가 문자열일때.
        {
            right = n - 1;
            left = 0;
            while (right >= left)
            {
                mid = (right + left) / 2;
                if (strcmp(temp, list_st[mid].name) == 0)
                {
                    printf("%d\n", list_st[mid].num);
                    break;
                }
                else
                {
                    if (strcmp(temp, list_st[mid].name) > 0)
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
            }
        }

        else
        {
            printf("%s\n",list[atoi(temp)-1].name);
        }
    }
    return 0;
}