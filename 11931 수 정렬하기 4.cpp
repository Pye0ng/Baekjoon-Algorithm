#include<stdio.h>
#include<algorithm>
int d[1000001];

bool cmp(int a, int b){ return a>b; } 

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	std::sort(d, d+n, cmp);
	for(i=0; i<n; i++) printf("%d\n", d[i]);
}
