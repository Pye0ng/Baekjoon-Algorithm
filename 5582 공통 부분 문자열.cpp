#include<stdio.h>
#include<string.h>
char a[4100], b[4100];
int cnt, dp[4100][4100];

int max(int p, int q){ return p>q?p:q; }

int main(){
	scanf("%s %s", a, b);
	for(int i=0; i<strlen(a); i++)
		for(int j=0; j<strlen(b); j++)
			if(a[i]==b[j]){
				dp[i+1][j+1]=dp[i][j]+1;
				cnt=max(cnt, dp[i+1][j+1]);
			}
	printf("%d", cnt); 
}
