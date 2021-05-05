#include<stdio.h>
int t, n, M=1e9+9;
long long int d[100010][4];

int main(){
	int i, j;
	scanf("%d", &t);
	d[1][1]=d[2][1]=d[2][2]=1; d[3][1]=d[3][2]=2;
	for(i=4; i<=100000; i++){
		d[i][1]=(d[i-1][2]+d[i-2][2]+d[i-3][2])%M;
		d[i][2]=(d[i-1][1]+d[i-2][1]+d[i-3][1])%M;
	}
	while(t--){
		scanf("%d", &n);
		printf("%lld %lld\n", d[n][1], d[n][2]);
	}
}
