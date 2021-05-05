#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
vector<pair<int, int> > v;
stack<int> s;
int n, cnt, a[1000100], dp[1000100];

int lower_bound(int k){
	int s=0, e=cnt;
	while(e>s){
		int m=(s+e)/2;
		if(dp[m]<k) s=m+1;
		else e=m;
	}
	return e;
}

int main(){
	int i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	dp[0]=a[0];
	v.push_back({0, a[0]});
	for(i=1; i<n; i++){
		if(dp[cnt]<a[i]){
			dp[++cnt]=a[i];
			v.push_back({cnt, a[i]});
		}
		else{
			int k=lower_bound(a[i]);
			dp[k]=a[i];
			v.push_back({k, a[i]});
		}
	}
	printf("%d\n", cnt+1);
	for(i=n-1; i>=0; i--){
		if(cnt==v[i].first){
			s.push(v[i].second);
			cnt--;
		}
	}
	while(!s.empty()){
		printf("%d ", s.top());
		s.pop();
	}
}
