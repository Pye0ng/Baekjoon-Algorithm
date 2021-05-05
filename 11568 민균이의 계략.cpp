#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int d[1010];

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	v.push_back(0);
	for(i=1; i<=n; i++){
		if(d[i]>v.back()) v.push_back(d[i]);
		else *lower_bound(v.begin(), v.end(), d[i])=d[i];
	}
	printf("%d", v.size()-1);
}
