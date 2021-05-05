#include<stdio.h>
#include<math.h>
int n, d[33];

int main(){
	int i, j;
	scanf("%d", &n);
	d[0]=1; d[2]=3;
	if(n%2) printf("0");
	else{
		for(i=4; i<=n; i+=2){
			d[i]+=d[i-2]*3;
			for(j=4; j<=i; j+=2) d[i]+=d[i-j]*2;
		}
		printf("%d", d[n]);
	}
}
