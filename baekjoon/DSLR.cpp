#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define VAL_MIN 0
#define VAL_MAX 9999

#define QUEUE_SIZE 1000000
#define OP_LEN 120

int op_D(int n)
{
    n *= 2;
    n %= VAL_MAX + 1;

    return n;
}

int op_S(int n)
{
    n -= 1;
    n += VAL_MAX + 1;
    n %= VAL_MAX + 1;

    return n;
}

int op_L(int n)
{
    return (n * 10 + n / 1000) % (VAL_MAX + 1);
}

int op_R(int n)
{
    return (n % 10) * 1000 + (n / 10);
}

int q[QUEUE_SIZE + 1];
int head, tail;

void init()
{
    head = tail = 0;
}

int size()
{
    int begin = head;
    int end = head <= tail ? tail : tail + QUEUE_SIZE + 1;

    return end - begin;
}

int empty()
{
    return size() == 0;
}

void push(int i)
{
    q[tail++] = i;
    tail %= QUEUE_SIZE + 1;
}

int pop()
{
    if(empty())
        return -1;

    int ret = q[head++];
    head %= QUEUE_SIZE + 1;
    return ret;
}

int front()
{
    if(empty())
        return -1;

    return q[head];
}

int back()
{
    if(empty())
        return -1;

    return q[tail - 1];
}

void solve(int from, int to)
{
    bool visited[10000] = { false, };
    char op_to_get[10000] = { '\0', };
    int num_to_get[10000];
    for (int i = 0; i < 10000; i++)
        num_to_get[i] = -1;

    push(from);

    while (!empty())
    {
        int value = pop();

        int D = op_D(value);
        if (num_to_get[D] == -1)
        {
            num_to_get[D] = value;
            op_to_get[D] = 'D';
            push(D);
        }
        if (D == to)
            break;

        int S = op_S(value);
        if (num_to_get[S] == -1)
        {
            num_to_get[S] = value;
            op_to_get[S] = 'S';
            push(S);
        }
        if (S == to)
            break;

        int L = op_L(value);
        if (num_to_get[L] == -1)
        {
            num_to_get[L] = value;
            op_to_get[L] = 'L';
            push(L);
        }
        if (L == to)
            break;

        int R = op_R(value);
        if (num_to_get[R] == -1)
        {
            num_to_get[R] = value;
            op_to_get[R] = 'R';
            push(R);
        }
        if (R == to)
            break;
    }

    char op[40];
    int op_index = 0;
    int num = to;
    while (num != from)
    {
        op[op_index++] = op_to_get[num];
        num = num_to_get[num];
    }

    while (--op_index > -1)
        printf("%c", op[op_index]);
    printf("\n");
}

int main(void)
{
    int N, from, to;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &from, &to);

        init();
        solve(from, to);
    }

    return 0;
}