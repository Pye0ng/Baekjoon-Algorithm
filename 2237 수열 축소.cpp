#include<stdio.h>
#include<algorithm>
#include<vector>
#define M 103
#define N 20000
using namespace std;
vector<bool> visited(M, false);
int a[M], dp[M][N*2+3];

int main(){
	int n, k, t, i, j;
	scanf("%d %d", &n, &t);
	for(i=1; i<=n; i++) scanf("%d", &a[i]);
	dp[1][a[1]+N]=a[1];
	dp[2][a[1]-a[2]+N]=-a[2];
	for(i=3; i<=n; i++){
		for(j=0; j<=N*2; j++){
			if(dp[i-1][j]!=0){
				if(j+a[i]<=N*2) dp[i][j+a[i]]=a[i];
				if(j-a[i]>=0) dp[i][j-a[i]]=-a[i];
			}
		}
	}
	k=t;
	t+=N;
	for(i=n; i>=1; i--){
		if(dp[i][t]>0){
			t-=a[i];
			visited[i]=1;
		}
		else t+=a[i];
	}
	int s=0, sum=0;
	for(i=1; i<=n; i++){
		if(!visited[i]){
			while(i<n&&visited[i+1]){
				printf("%d\n", i-s);
				s++; i++;
			}
		}
	}
	for(i=0; i<n-s-1; i++) printf("1\n");
}
