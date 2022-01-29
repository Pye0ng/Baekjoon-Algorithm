#include<stdio.h>
#include<algorithm>
int d[10100];

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	std::sort(d, d+n);
	for(i=0; i<n; i++){
		if(d[i]<=m) m++;
		else break;
	}
	printf("%d", m);
}
