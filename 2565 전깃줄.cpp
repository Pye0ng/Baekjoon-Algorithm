#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> d, v;
int n, p[510];

int main(){
	int i;
	scanf("%d", &n);
	v.push_back(0);
	for(i=1; i<=n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		p[a]=b;
	}
	for(i=1; i<=500; i++)
		if(p[i]) d.push_back(p[i]);
	for(i=0; i<d.size(); i++){
		if(d[i]>v.back()) v.push_back(d[i]);
		else *lower_bound(v.begin(), v.end(), d[i])=d[i];
	}
	printf("%d", n-v.size()+1);
}
