#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
typedef long long int ll;
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
int a[1000100], b[1000100], x[1000100], ans;

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &a[i]);
	for(i=1; i<=n; i++) scanf("%d", &b[i]);
	for(i=1; i<n; i++){
		x[i]=a[i]^b[i];
		if(x[i]==0) continue;
		a[i+1]^=x[i]; ans++;
	}
	printf("%d", a[n]==b[n]?ans:-1);
}