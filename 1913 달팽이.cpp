#include<stdio.h>
int s[1001][1001];
int n, m, row=0, col=-1, re=1, lim=1;

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(int cnt=n*n; cnt>=1;){
		for(i=0; i<=n-lim; i++){
			col+=re;
			s[row][col]=cnt--;
		}
		for(i=0; i<=n-lim-1; i++){
			row+=re;
			s[row][col]=cnt--;
		}
		lim++;
		re=-re;
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%d ", s[j][i]);
			if(m==s[i][j]){
				row=i+1;
				col=j+1;
			}
		}
		printf("\n");
	}
	printf("%d %d", col, row);
	return 0;
}
