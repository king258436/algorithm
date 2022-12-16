#include <stdio.h>

int computer[100][100];
int virus = 0;
int visited[100];

void check_connect(int n, int k);

int main() {
    int vertex;
    int line;
    int x, y;
    scanf("%d", &vertex);
    scanf("%d", &line);

    for (int i = 0; i < line; i++) {
        scanf("%d %d", &x, &y);
        computer[x - 1][y - 1] = 1;
        computer[y - 1][x - 1] = 1;
    }
    
    visited[0]=1;
    check_connect(vertex,0);
    printf("%d",virus);
    return 0;
}

void check_connect(int n, int k) {
    for (int i = 0; i < n; i++) {
        if (computer[k][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            check_connect(n, i);
            virus++;
        }
    }
}