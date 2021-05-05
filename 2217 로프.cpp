#include<stdio.h>
#include<algorithm>
int n, mx, d[100001];

int main(){
	int i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	std::sort(d, d+n);
	for(i=0; i<n; i++)
		if(d[i]*(n-i)>mx) mx=d[i]*(n-i);
	printf("%d", mx);
}
