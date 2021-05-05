#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int, int> > v;
int n, k, sum;

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &k);
		v.push_back({k, i});
	}
	sort(v.begin(), v.end());
	for(i=0; i<n; i++)
		for(j=0; j<=i; j++) sum+=v[j].first;
	printf("%d", sum);
}
