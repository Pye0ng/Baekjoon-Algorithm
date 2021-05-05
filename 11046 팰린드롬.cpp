#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, r, c, d[2000010], p[2000010];

int main(){
	int a, b, e, t, i;
	scanf("%d", &n);
	d[0]=-1;
	for(i=0; i<n; i++){
		scanf("%d", &d[2*i+1]);
		d[2*i+2]=-1;
	}
	for(i=0; i<2*n+1; i++){
		if(i<=r) p[i]=min(p[2*c-i], r-i);
		while(p[i]<i&&i+p[i]<2*n&&d[i+p[i]+1]==d[i-p[i]-1]) p[i]++;
		if(r<i+p[i]){ r=i+p[i]; c=i; }
	}
	scanf("%d", &m);
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		e=b-a+1;
		a--; a*=2; a++;
		b--; b*=2; b++;
		t=(a+b)/2;
		printf("%d\n", p[t]>=e);
	}
}
