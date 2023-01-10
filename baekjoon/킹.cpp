#include <stdio.h>
#include <string.h>

int main() {
    int arr[8][8]={0,};
    char RockRow, KingRow;
    int RRow, KRow;
    int RockColumn, KingColumn;
    int n;
    int i, j;

    scanf("%c%d", &KingRow, &KingColumn);
    KRow = KingRow - 'A';
    KingColumn--;
    arr[KRow][KingColumn] = 1;  // 킹위치

    scanf(" %c%d", &RockRow, &RockColumn);
    RRow = RockRow - 'A';
    RockColumn--;
    arr[RRow][RockColumn] = 2;  // 돌 위치

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        char move[3];
        scanf("%s", move);
        if (move[0] == 'B') {
            if (KingColumn != 0) {
                arr[KRow][KingColumn--] = 0;
                arr[KRow][KingColumn] = 1;
                if (arr[KRow][KingColumn] == arr[RRow][RockColumn]){
                    if(RockColumn==0){
                        arr[KRow][KingColumn++]=2;
                        arr[KRow][KingColumn]=1;
                    }
                    else{
                        arr[RRow][--RockColumn] = 2;
                    }
                }
            }
        } else if (move[0] == 'T') {
            if (KingColumn != 7) {
                arr[KRow][KingColumn++] = 0;
                arr[KRow][KingColumn] = 1;
                if (arr[KRow][KingColumn] == arr[RRow][RockColumn]){
                    if(RockColumn==7){
                        arr[KRow][KingColumn--]=2;
                        arr[KRow][KingColumn]=1;
                    }
                    else{
                        arr[RRow][++RockColumn] = 2;
                    }
                }
            }
        } else if (move[0] == 'R' && move[1] == 0) {
            if (KRow != 7) {
                arr[KRow++][KingColumn] = 0;
                arr[KRow][KingColumn] = 1;
                if (arr[KRow][KingColumn] == arr[RRow][RockColumn]){
                    if(RRow==7){
                        arr[KRow--][KingColumn]=2;
                        arr[KRow][KingColumn]=1;
                    }
                    else{
                        arr[++RRow][RockColumn] = 2;
                    }
                }
            }
        } else if (move[0] == 'L' && move[1] == 0) {
            if (KRow != 0) {
                arr[KRow--][KingColumn] = 0;
                arr[KRow][KingColumn] = 1;
                if (arr[KRow][KingColumn] == arr[RRow][RockColumn]){
                    if(RRow==0){
                        arr[KRow++][KingColumn]=2;
                        arr[KRow][KingColumn]=1;
                    }
                    else{
                        arr[--RRow][RockColumn] = 2;
                    }
                }
            }
        } else if (move[0] == 'R' && move[1] == 'T') {
            if (KingColumn != 7&& KRow != 7) {
                arr[KRow++][KingColumn++] = 0;
                arr[KRow][KingColumn] = 1;
                if (arr[KRow][KingColumn] == arr[RRow][RockColumn]){
                    if(RockColumn==7||RRow==7){
                        arr[KRow--][KingColumn--]=2;
                        arr[KRow][KingColumn]=1;
                    }
                    else{
                        arr[++RRow][++RockColumn] = 2;
                    }
                }
            }
        } else if (move[0] == 'L' && move[1] == 'T') {
            if (KRow != 0 && KingColumn != 7) {
                arr[KRow--][KingColumn++] = 0;
                arr[KRow][KingColumn] = 1;
                if (arr[KRow][KingColumn] == arr[RRow][RockColumn]){
                    if(RRow==0||RockColumn==7){
                        arr[KRow++][KingColumn--]=2;
                        arr[KRow][KingColumn]=1;
                    }
                    else{
                        arr[--RRow][++RockColumn] = 2;
                    }
                }
            }
        } else if (move[0] == 'R' && move[1] == 'B') {
            if (KRow != 7 && KingColumn != 0) {
                arr[KRow++][KingColumn--] = 0;
                arr[KRow][KingColumn] = 1;
                if (arr[KRow][KingColumn] == arr[RRow][RockColumn]){
                    if(RRow==7||RockColumn==0){
                        arr[KRow--][KingColumn++]=2;
                        arr[KRow][KingColumn]=1;
                    }
                    else{
                        arr[++RRow][--RockColumn] = 2;
                    }
                }
            }
        } else if (move[0] == 'L' && move[1] == 'B') {
            if (KingColumn != 0 && KRow != 0) {
                arr[KRow--][KingColumn--] = 0;
                arr[KRow][KingColumn] = 1;
                if (arr[KRow][KingColumn] == arr[RRow][RockColumn]){
                    if(RockColumn==0||RRow==0){
                        arr[KRow++][KingColumn++]=2;
                        arr[KRow][KingColumn]=1;
                    }
                    else{
                        arr[--RRow][--RockColumn] = 2;
                    }
                }
            }
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (arr[i][j] == 1){
                KingRow=i+'A';
                printf("%c%d\n", KingRow, j+1);
                break;
            }
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (arr[i][j] == 2){
                RockRow=i+'A';
                printf("%c%d", RockRow, j+1);
                return 0;
            }
        }
    }
}