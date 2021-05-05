#include<stdio.h>
#define m 1000000
#define M 1000000000
int n, d[2000020];

int abs(int k){ return k>0?k:-k; }

void ch(int k){
	if(k>0) printf("1\n");
	else if(k==0) printf("0\n");
	else printf("-1\n");
}

int main(){
	int i;
	scanf("%d", &n);
	d[m]=0; d[m+1]=d[m-1]=1;
	if(n>0){
		for(i=m+2; i<=m+n; i++) d[i]=(d[i-1]%M+d[i-2]%M)%M;
		ch(d[n+m]);
		printf("%d", d[n+m]);
	}
	else if(n<0){
		for(i=m-1; i>=m+n; i--) d[i]=(d[i+2]%M-d[i+1]%M)%M;
		ch(d[n+m]);
		printf("%d", abs(d[n+m]));
	}
	else printf("0\n0");
}
