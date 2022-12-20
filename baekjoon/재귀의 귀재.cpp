#include <stdio.h>
#include <string.h>

int cnt = 0;

int recursion(const char *s, int l, int r) {
    cnt++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) { return recursion(s, 0, strlen(s) - 1); }

int main() {
    char s[1001];
    int t, p;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%s", s);
        p = isPalindrome(s);
        printf("%d %d\n", p, cnt);
        cnt = 0;
    }
    return 0;
}