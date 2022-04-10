#include<stdio.h>
int d[12];

int main(){
	int n, s, r, t, i;
	scanf("%d %d %d", &n, &s, &r);
	for(i=0; i<s+r; i++){
		scanf("%d", &t);
		if(i<s) d[t]--;
		else d[t]++;
	}
	t=0;
	for(i=1; i<n; i++)
		if((d[i]==-1&&d[i+1]==1)||(d[i]==1&&d[i+1]==-1)) d[i]=d[i+1]=0;
	for(i=1; i<=n; i++) t+=d[i]==-1;
	printf("%d", t);
}
