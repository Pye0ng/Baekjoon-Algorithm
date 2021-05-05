#include<stdio.h>
int min;

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<=n/5; i++)
		for(int j=0; j<=(n-5*i)/3; j++){ if(5*i+3*j==n) min=i+j; }
	if(min) printf("%d", min);
	else printf("-1");
}
