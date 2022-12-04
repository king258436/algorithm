#include <stdio.h>

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    printf("%d", (n / 5) + (n / 25) + (n / 125));
    return 0;
}