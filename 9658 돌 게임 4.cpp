#include<stdio.h>
int d[1010];

int main(){
	int n, i;
	scanf("%d", &n);
	d[2]=d[4]=1;
	for(i=5; i<=n; i++) d[i]=!(d[i-1]&&d[i-3]&&d[i-4]);
	if(d[n]) printf("SK");
	else printf("CY");
}
