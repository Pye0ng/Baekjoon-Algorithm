#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;

int main(){
	int n, t, m=0, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &t);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	for(i=n-1; i>=0; i--)
		m=max(m, v[i]+n-i+1);
	printf("%d", m);
}
