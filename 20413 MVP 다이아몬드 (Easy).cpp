#include<stdio.h>
char c[40];
int m, sum;

int main(){
	int n, s, g, p, d, i;
	scanf("%d %d %d %d %d", &n, &s, &g, &p, &d);
	scanf("%s", c);
	if(c[0]=='B') m=s-1;
	if(c[0]=='S') m=g-1;
	if(c[0]=='G') m=p-1;
	if(c[0]=='P') m=d-1;
	if(c[0]=='D') m=d;
	sum+=m;
	for(i=1; i<n; i++){
		if(c[i]=='B') m=s-1-m;
		if(c[i]=='S') m=g-1-m;
		if(c[i]=='G') m=p-1-m;
		if(c[i]=='P') m=d-1-m;
		if(c[i]=='D') m=d;
		sum+=m;
	}
	printf("%d", sum);
}
