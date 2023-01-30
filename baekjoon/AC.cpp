#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numOfdata;

int main() {
    int Tc, c;
    int i, j;
    char garbage;
    int num;

    scanf("%d", &Tc);
    for (c = 0; c < Tc; c++) {
        int *arr = (int*)malloc(sizeof(int)*100001);
        char *command = (char*)malloc(sizeof(char)*100001);
        scanf("%s", command);
        scanf("%d", &numOfdata);
        scanf(" %c", &garbage);

        for (j = 0; j < numOfdata; j++) {
            scanf("%d", &arr[j]);

            if (j != numOfdata - 1) scanf(" %c", &garbage);
        }
        scanf(" %c", &garbage);

        int rear = numOfdata - 1;
        int front = 0;
        int flag=1;

        for (i = 0; i < strlen(command); i++) {
            if (command[i] == 'R') {
                if (flag == 1)
                    flag = 0;
                else
                    flag = 1;
            } 
            else if (command[i] == 'D') {
                if (front>rear) {
                    printf("error\n");
                    rear--;
                    break;
                }
                if (flag == 1) {
                    front++;
                } else {
                    rear--;
                }
            }
        }
        if (rear>=front && flag == 1) {
            printf("[");
            for (i = front; i <= rear; i++) {
                printf("%d", arr[i]);
                if (i != rear) printf(",");
            }
            printf("]\n");
        } else if (rear>=front && flag == 0) {
            printf("[");
            for (i = rear; i >= front; i--) {
                printf("%d", arr[i]);
                if (i != front) printf(",");
            }
            printf("]\n");
        }
        else if(rear==front-1) printf("[]\n");
        free(arr);
        free(command);
    }
    return 0;
}
