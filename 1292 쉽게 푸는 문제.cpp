#include<stdio.h>
int d[1001], cnt, sum;

int main(){
	int a, b, n, i;
	scanf("%d %d", &a, &b);
	for(i=1; i<=50; i++)
		for(int j=1; j<=i; j++) d[cnt++]=i;
	for(i=a-1; i<=b-1; i++) sum+=d[i];
	printf("%d", sum);
}
