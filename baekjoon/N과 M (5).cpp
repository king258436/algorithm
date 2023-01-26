#include <stdio.h>
#include <stdlib.h>

int n, m;
int result[10];
int visited[10001];
int arr[10];

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void dfs(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } 
    else {
        for (int i = 0; i < n; i++) {
            if (visited[arr[i]] == 0) {
                result[depth]=arr[i];
                visited[arr[i]]=1;
                dfs(depth + 1);
                visited[arr[i]]=0;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    dfs(0);
    return 0;
}