#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct ds{ int b, e, p; };
vector<ds> v;
int dp[30];

bool cmp(ds a, ds b){ return a.b<b.b; }
int mx(int a, int b){ return a>b?a:b; }

int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		ds a;
		scanf("%d %d %d", &a.b, &a.e, &a.p);
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp);
	dp[1]=v[0].p;
	dp[2]=mx(v[0].p, v[1].p);
	for(i=3; i<=n; i++)
		for(j=1; j<i-1; j++) dp[i]=mx(dp[i-1], v[i-1].p+dp[j]);
	printf("%d", dp[n]);
}
