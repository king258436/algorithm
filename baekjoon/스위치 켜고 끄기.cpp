#include <stdio.h>

int main() {
    int switch_num, student_num, gender, num, s[100];
    int i, j;
    scanf("%d", &switch_num);
    for (i = 1; i <= switch_num; i++) {
        scanf("%d", &s[i]);
    }
    scanf("%d", &student_num);
    for (i = 0; i < student_num; i++) {
        scanf("%d %d", &gender, &num);
        int cnt = 0;
        if (gender == 1) {
            for (j = num; j <= switch_num; j = j + num) {
                s[j] = !s[j];
            }
        } else {
            while (s[num - cnt] == s[num + cnt]) {
                if (num - cnt <= 0 || num + cnt > switch_num) break;
                cnt++;
            }
            for (j = num - cnt + 1; j <= num + cnt - 1; j++) {
                s[j] = !s[j];
            }
        }
    }
    int cnt=0;
    for (int i = 1; i <= switch_num; i++) {
        if(cnt++%20==0&&cnt>=20) printf("\n");
        printf("%d ", s[i]);
    }
    return 0;
}