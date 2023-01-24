#include <stdio.h>
#include <string.h>

char stack[31];
int top = -1;

void PUSH(char data) { stack[++top] = data; }

char POP() {
    if (top == -1) return 0;
    return stack[top--];
}

int main() {
    char str[31];
    int temp = 1, result = 0;
    int i, j;
    int flag=0;

    scanf("%s", str);

    for (i = 0; i < strlen(str); i++) {

        if (str[i] == '(') {
            PUSH('(');
            temp = temp * 2;
        } 

        else if (str[i] == '[') {
            PUSH('[');
            temp = temp * 3;
        } 

        else if (str[i] == ')') {

            if (POP() != '(') {
                flag=1;
                break;
            }

            if(str[i-1]=='(') {
                result = result + temp;
                temp = temp / 2;
            }
            else temp = temp/2;
        }
        else if(str[i]==']'){
            if(POP()!='['){
                flag=1;
                break;
            }

            if(str[i-1]=='['){
                result = result + temp;
                temp = temp/3;
            }
            else temp = temp/3;
        }
    }
    if(flag==0&&top==-1) printf("%d",result);
    else printf("0");
    return 0;
}