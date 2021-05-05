#include<stdio.h>
int n, k, ch, d[30010], p[1000010];

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	for(i=1; i<n; i++){
		scanf("%d", &k);
		if(p[d[i]]<k) p[d[i]]=k;
	}
	if(n==1){
		printf("권병장님, 중대장님이 찾으십니다");
		return 0;
	}
	for(i=1; i<n; i++){
		if(d[i]==d[i+1]) continue;
		for(j=1; j<=i; j++){
			if(d[j]==d[j+1]) continue;
			if(d[j]+p[d[j]]>=d[i+1]){ ch=1; break; }
		}
		if(!ch){ printf("엄마 나 전역 늦어질 것 같아"); return 0; }
		ch=0;
	}
	printf("권병장님, 중대장님이 찾으십니다");
}
