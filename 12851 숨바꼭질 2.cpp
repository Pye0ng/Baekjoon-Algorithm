#include<stdio.h>
#include<queue>
using namespace std;
queue<pair<int, int> > q;
int ch, cnt, dp[100010];

int main(){
	int n, k, a, b, s, i;
	scanf("%d %d", &n, &k);
	if(n==k){ printf("0\n1"); return 0; }
	dp[n]=1; q.push({n, 1});
	while(!q.empty()){
		s=q.size();
		for(i=0; i<s; i++){
			a=q.front().first; b=q.front().second; q.pop(); 
			dp[a]+=b; if(a==k) ch=1;
			if(a<50001&&dp[a*2]==0) q.push({a*2, b});
			if(a<100000&&dp[a+1]==0) q.push({a+1, b});
			if(a>0&&dp[a-1]==0) q.push({a-1, b});
		}
		if(ch){ printf("%d\n%d", cnt, dp[k]); return 0; } cnt++;
	}
}
