#include<stdio.h>
#include<algorithm>
int a[1000001];

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	std::sort(a, a+n);
	for(i=0; i<n; i++) printf("%d\n", a[i]);
}
