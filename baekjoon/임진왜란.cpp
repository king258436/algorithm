#include <stdio.h>
#include <string.h>

typedef struct a {
    char name[16];
    int num;
} info;
int main() {
    info answer[2500], collect[2500];
    int n, i,j,cnt=0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", collect[i].name);
        collect[i].num = i;
    }
    for (i = 0; i < n; i++) {
        scanf("%s", answer[i].name);
        for(j=0;j<n;j++){
            if(!strcmp(collect[j].name,answer[i].name)){
                answer[i].num=collect[j].num;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(answer[i].num>answer[j].num){
                cnt++;
                continue;
            }
        }
    }
    printf("%d/%d",n*(n-1)/2-cnt,n*(n-1)/2);
    return 0;
}