#include<stdio.h>
int d[100100], non;

int main(){
	int n, min=100100, max=0, t, q, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &t); d[t]++;
		if(t<min) min=t;
		if(t>max) max=t;
	}
	if(n&1){ printf("-1"); return 0; }
	t=min+1;
	for(i=1; i<=n; i++){
		if(d[t]==1) break;
		q=t; d[q]--;
		if(d[t-1]>1){ t--; continue; }
		if(d[t+1]>1){ t++; continue; }
		q++;
	}
	if(q!=max){ printf("-1"); return 0; }
	for(i=min; i<=max; i++)
		if(d[i]!=1){ printf("-1"); return 0; }
	printf("1");
}
