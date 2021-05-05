#include<stdio.h>
#include<memory.h>
int n, nw, d[510], sp[510], ch[510], dp[510][510];

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d %d %d", &d[i], &sp[i], &ch[i]);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i==0&&j==0) dp[i][j]=1;
			else if(i!=j||(i==n-1&&j==n-1)){
				if(i>j){
					for(int k=0; k<i; k++)
						if(d[k]+sp[k]>=d[i]) dp[i][j]+=dp[k][j];
				}
				else if(ch[j]){
					for(int k=0; k<j; k++)
						if(d[k]+sp[j]>=d[j]) dp[i][j]+=dp[i][k];
				}
			}
			dp[i][j]%=1000;
		}
	}
	printf("%d", dp[n-1][n-1]);
}
