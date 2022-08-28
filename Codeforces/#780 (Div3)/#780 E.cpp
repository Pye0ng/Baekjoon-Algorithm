#include<stdio.h>
char s[2020][2020];
int d[2020][2020];

int main(){
	int t, n, a, b, m, i, j, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n); a=0; b=0;
		for(i=0; i<n; i++) scanf("%s", s[i]);
		for(i=0; i<n; i++)
			for(j=0; j<n; j++){
				m=s[i][j]-'0'; a+=m;;
				d[i][j]=i>0&&j>0?d[i-1][j-1]+m:m;
			}
		m=d[n-1][n-1];
		for(i=1; i<n; i++){
			b=d[n-1][n-i-1]+d[i-1][n-1];
			if(b>m) m=b;
		}
		for(i=1; i<n; i++){
			b=d[n-i-1][n-1]+d[n-1][i-1];
			if(b>m) m=b;
		}
		printf("%d\n", n+a-2*m);
		for(i=0; i<n; i++)
			for(j=0; j<n; j++) d[i][j]=0;
	}
}
