#include<stdio.h>
#include<algorithm>
int d[500001];

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	std::sort(d, d+n);
	for(i=0; i<n; i++) printf("%d ", d[i]);
}
