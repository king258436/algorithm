#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sp {
    char site[21];
    char password[21];
} site_pw;

int compare(const void* first, const void* second) {
    site_pw* a = (site_pw*)first;
    site_pw* b = (site_pw*)second;
    if (strcmp(a->site, b->site) > 0)
        return 1;
    else
        return 0;
}

int main() {
    int i, n, m;
    site_pw* list = NULL;
    char target[21];

    scanf("%d %d", &n, &m);

    list = (site_pw*)malloc(sizeof(site_pw) * n);

    for (i = 0; i < n; i++) {
        scanf("%s %s", list[i].site, list[i].password);
    }

    qsort(list, n, sizeof(list[0]), compare);

    for (i = 0; i < m; i++) {
        scanf("%s", target);
        int left = 0, right = n - 1, mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (strcmp(target, list[mid].site) == 0) {
                printf("%s\n", list[mid].password);
                break;
            } else {
                if (strcmp(target, list[mid].site) > 0) {
                    left = mid + 1;
                } else
                    right = mid - 1;
            }
        }
    }
    free(list);
    return 0;
}