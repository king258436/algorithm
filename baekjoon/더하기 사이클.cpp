#include <stdio.h> 

int main(void) {
    
    int a,b,c,d=-1,result,input,count=0;
    
    scanf("%d", &input);
    result = input;
    
    while(d!=result) {
        a = input / 10;
        b = input % 10; // 주어진 수의 가장 오른쪽 자리 수
        c = (a+b) % 10; // 앞에서 구한 합의 가장 오른쪽 자리 수
        d = (b*10) + c; // 새로운 수
        input = d;
        count++;
    }
    printf("%d", count);
}