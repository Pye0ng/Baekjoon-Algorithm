#include<stdio.h>
#include<algorithm>
int n, k, cnt, d[100001];

int main(){
	int i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	scanf("%d", &k);
	std::sort(d, d+n);
	int p=0, q=n-1;
	while(p<q){
		if(d[p]+d[q]==k){
			p++; q--;
			cnt++;
		}
		else if(d[p]+d[q]>k) q--;
		else if(d[p]+d[q]<k) p++;
	}
	printf("%d", cnt);
}
