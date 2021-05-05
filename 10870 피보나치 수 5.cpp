#include<stdio.h>

int main(){
	int n, d[25];
	d[0]=0; 
	d[1]=d[2]=1;
	scanf("%d", &n);
	for(int i=3; i<=n; i++) d[i]=d[i-1]+d[i-2];
	printf("%d", d[n]);
}
