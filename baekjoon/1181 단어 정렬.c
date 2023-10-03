#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char word[51];
    int len;
}string;

int compar(const void* p1,const void* p2){
    string *num1=(string*)p1;
    string *num2=(string*)p2;
    if(num1->len<num2->len) return -1;
    else if(num1->len>num2->len) return 1;
    else {
       return strcmp(num1->word,num2->word);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    string *strarr=(string*)malloc(sizeof(string)*n);//동적할당
    for( int i=0;i<n;i++){
        scanf("%s",strarr[i].word);
        strarr[i].len=strlen(strarr[i].word);
    }
    qsort(strarr,n,sizeof(string),compar);
    printf("%s\n",strarr[0].word);
    for (int i=1;i<n;i++){
        if(strcmp(strarr[i-1].word,strarr[i].word)){
            printf("%s\n",strarr[i].word);
        }
    }
    free(strarr);
    return 0;
}