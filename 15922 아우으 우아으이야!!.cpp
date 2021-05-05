#include<stdio.h>
#include<utility>
#include<vector>
using namespace std;
typedef pair<int, int> p;
vector<p> v;
int ans;
p x;

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({a, b});
	}
	x.first=x.second=-1000000001;
	for(i=0; i<n; i++){
		if(v[i].first>x.second){
			ans+=x.second-x.first;
			x=v[i];
		}
		else if(x.second<v[i].second) x.second=v[i].second;
	}
	ans+=x.second-x.first;
	printf("%d", ans);
}
