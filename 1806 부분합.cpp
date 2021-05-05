#include<stdio.h>
int n, k, s=100010, d[100010];
int min(int a, int b){ return a<b?a:b; }

int main(){
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; i++){
		scanf("%d", &d[i]);
		if(d[i]>=k){ printf("1"); return 0; }
	}
	int p, q, cnt;
	p=q=1; cnt=d[1];
	while(p<=q&&q<=n){
		if(cnt>=k){ s=min(s, q-p+1); cnt-=d[p++]; }
		else cnt+=d[++q];
	}
	if(s==100010) printf("0");
	else printf("%d", s);
}
