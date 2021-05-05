#include<stdio.h>
char c[101];
int d[101];

int main(){
	int n, sum=0;
	scanf("%d %s", &n, c);
	for(int i=0; i<n; i++){
		d[i]=c[i]-'0';
		sum+=d[i];	
	}
	printf("%d", sum);
} 
