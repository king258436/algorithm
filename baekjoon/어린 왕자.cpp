#include <math.h>
#include <stdio.h>

typedef struct po {
    int x;
    int y;
} point;

int main() {
    point start, end, cir;
    int r, t, n, i, j;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        int cnt=0;
        scanf("%d %d %d %d", &start.x, &start.y, &end.x, &end.y);
        scanf("%d", &n);
        for (j = 0; j < n; j++) {
            scanf("%d %d %d", &cir.x, &cir.y, &r);
            if (pow(r, 2) > pow(cir.x - start.x, 2) + pow(cir.y - start.y, 2) && pow(r, 2) < pow(cir.x - end.x, 2) + pow(cir.y - end.y, 2)) {
                cnt++;
            }
            else if(pow(r, 2) > pow(cir.x - end.x, 2) + pow(cir.y - end.y, 2)&&pow(r, 2) < pow(cir.x - start.x, 2) + pow(cir.y - start.y, 2)){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}