#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int d[200010];

int main(){
	int n, i;
	v.push_back(0);
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	for(i=0; i<n; i++){
		if(d[i]>v.back()) v.push_back(d[i]);
		else *lower_bound(v.begin(), v.end(), d[i])=d[i];
	}
	printf("%d", n-v.size()+1);
}
