#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;

int main(){
	int n, k, i;
	scanf("%d", &n);
	v.push_back(0);
	for(i=1; i<=n; i++){
		scanf("%d", &k);
		if(k>v.back()) v.push_back(k);
		else *lower_bound(v.begin(), v.end(), k)=k;
	}
	printf("%d", v.size()-1);
}
