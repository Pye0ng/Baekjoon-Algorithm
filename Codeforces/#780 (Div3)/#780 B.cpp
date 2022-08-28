#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
ll a;

int main(){
	int t, n, ch, i;
	scanf("%d", &t);
	while(t--){
		ch=0;
		vector<ll> v;
		v.push_back(0);
		scanf("%d", &n);
		for(i=0; i<n; i++){
			scanf("%lld", &a);
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		for(i=1; i<=n; i++){
			if(i==1){
				if(n==1) ch=(v[1]>1);
				else ch=(v[2]-v[1]>1);
			}
			else if(i==n) ch=(v[n]-v[n-1]>1);
			else ch=(v[i+1]-v[i]>1)&&(v[i]-v[i-1]>1);
		}
		printf("%s\n", ch?"NO":"YES");
	}
}
