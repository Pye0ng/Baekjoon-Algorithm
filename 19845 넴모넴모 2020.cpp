#include<stdio.h>
#include<algorithm>
using namespace std;
int n, q, d[250010];

int nemo(int x, int y, pair<int, int> p[]){
	int cnt=0, a=y, b=n, m, i;
	if(d[y]>x) cnt+=d[y]-x;
	while(a<=b){
		m=(a+b)/2;
		if(d[m]>=x){
			if(m==n) break;
			else if(d[m+1]<x) break;
			a=m+1;
		}
		else b=m-1;
	}
	cnt+=m-y+1;
	return cnt;
}

int main(){
	int x, y, i;
	pair<int, int> p[250010];
	scanf("%d %d", &n, &q);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
		p[i-1].first=d[i];
		p[i-1].second=i;
	}
	for(i=1; i<=q; i++){
		scanf("%d %d", &x, &y);
		if(x>d[y]) printf("0\n");
		else printf("%d\n", nemo(x, y, p));
	}
}
