#include<stdio.h>
int n, i, d[25];

int main(){
	scanf("%d", &n);
	d[0]=d[1]=1; d[2]=2; d[3]=4; d[4]=7;
	for(i=5; i<=n; i++){
		d[i]=2*d[i-1];
		if(i%2==0) d[i]-=d[i-4]+d[i-5]; 
	}
	printf("%d", d[n]);
}
