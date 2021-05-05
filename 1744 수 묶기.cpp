#include<stdio.h>
#include<algorithm>
int n, k, sum, d[10010];
bool cmp(int a, int b){ return a>b; }

int main(){
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	std::sort(d+1, d+n+1, cmp);
	int p=1, q=n;
	while(p<=n&&d[p]>0){
		if(d[p+1]>0&&p<n){
			sum+=(d[p]*d[p+1]>d[p]+d[p+1])?d[p]*d[p+1]:d[p]+d[p+1];
			p+=2;
		}
		else sum+=d[p++];
	}
	while(p<=q&&d[q]<=0){
		if(d[q-1]<=0){
			sum+=d[q]*d[q-1];
			q-=2;
		}
		else sum+=d[q--];
	}
	if(n==1) printf("%d", d[1]);
	else printf("%d", sum);
}
