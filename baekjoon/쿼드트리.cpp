#include <stdio.h>
char map[64][64];


int check(int x, int y, int n) {
    char start = map[x][y];
    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (start != map[j][i]) return -1;
        }
    }
    return start-'0';
}

void recursion(int x, int y, int n) {
    int result=check(x,y,n);
    if(result>=0) printf("%d",result);
    else {
        printf("(");
        recursion(x,y,n/2);
        recursion(x+n/2,y,n/2);
        recursion(x,y+n/2,n/2);
        recursion(x+n/2,y+n/2,n/2);
        printf(")");
    }
}

int main() {
    int i, j;
    int n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf(" %c", &map[j][i]);
        }
    }
    recursion(0,0,n);
}