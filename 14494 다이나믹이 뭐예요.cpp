 #include<stdio.h>
 int n, m, d[1010][1010];
 
 int main(){
	int i, j, M=1e9+7;
	scanf("%d %d", &m, &n);
	d[1][1]=1;
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++){
			if(i+j==2) continue;
			d[i][j]=(d[i][j-1]+(d[i-1][j-1]+d[i-1][j])%M)%M;
		}
	printf("%d", d[n][m]);
}
