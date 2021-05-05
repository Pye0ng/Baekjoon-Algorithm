#include<stdio.h>
#include<algorithm>
int d[5000001];

int main(){
	int n, k, i;
	scanf("%d %d", &n, &k);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	std::sort(d, d+n);
	printf("%d ", d[k-1]);
}
