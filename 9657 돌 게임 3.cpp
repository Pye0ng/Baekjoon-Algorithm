#include<stdio.h>
int n, i, d[1010];

int main(){
	d[1]=d[3]=d[4]=1;
	scanf("%d", &n);
	for(i=5; i<=n; i++)
		if(!(d[i-1]&&d[i-3]&&d[i-4])) d[i]=1;
	if(d[n]) printf("SK");
	else printf("CY");
}
