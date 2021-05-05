#include<stdio.h>
int n, cnt, ans, a[4000010], pr[500010];

void prime(){
	int i, j;
	for(i=2; i<=n; i++) a[i]=i;
	for(i=2; i<=n; i++){
		if(a[i]==0) continue;
		for(j=2*i; j<=n; j+=i) a[j]=0;
	}
	for(i=2; i<=n; i++)
		if(a[i]!=0) pr[cnt++]=a[i];
}

int main(){
	int i;
	scanf("%d", &n);
	prime();
	int p=0, q=0, s=0;
	while(q<=cnt){
		if(s<n){
			s+=pr[q++];
			continue;
		}
		if(s==n) ans++;
		s-=pr[p++];
	}
	if(n==1) printf("0");
	else printf("%d", ans);
}
