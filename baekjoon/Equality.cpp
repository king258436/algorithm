#include <stdio.h>
int main(){
	int a,b,sum,real;
	char plus,equal;
	scanf("%d %c %d %c %d",&a,&plus,&b,&equal,&sum);
	real = a+b;
	if(real != sum){
		printf("NO");
	}
	else printf("YES");
	return 0;

}