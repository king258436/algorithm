#include <stdio.h>
#include <string.h>

int top = -1;
int stack[100000] = {0};
int sequence[100000] = {0};
char printstack[200001] = {0};
int stack_num = 1; //다음으로 stack에 들어갈 수
int cnt = 0;

void push(int data)
{
    top++;
    stack[top] = data;

    printstack[cnt] = '+';

    cnt++;
    stack_num++;
}

void pop()
{
    top--;
    printstack[cnt] = '-';
    cnt++;
}

int main()
{
    int n ;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &sequence[i]);
    }

    for (int i = 0; i < n; i++)
    {
        while(1){
            if (sequence[i] > stack[top]||top==-1)
            {
                push(stack_num);
            }

            if (sequence[i] == stack[top]){
                pop();
                break;
            }

            else if(sequence[i]<stack[top])
            {
                printf("NO");
                return 0;
            }
        }
    }
    for (int k = 0; k < strlen(printstack); k++)
    {
        printf("%c\n", printstack[k]);
    }
    return 0;
}