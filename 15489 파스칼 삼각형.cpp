#include<stdio.h>
int r, c, w, cnt=1, d[33][33];
long long int sum;

int main(){
	int i, j;
	scanf("%d %d %d", &r, &c, &w);
	d[1][1]=1;
	for(i=1; i<=r+w; i++){
		for(j=1; j<=i; j++){
			if(i!=1) d[i][j]=d[i-1][j-1]+d[i-1][j];
			if((r<=i&&i<r+w)&&(c<=j&&j<c+cnt)) sum+=d[i][j];
		}
		if(r<=i&&i<r+w) cnt++;
	}
	printf("%lld", sum);
}
