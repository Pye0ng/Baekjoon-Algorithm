#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int t, n, k, i;
	scanf("%d", &t);
	while(t--){
		vector<int> v;
		v.push_back(0);
		scanf("%d", &n);
		for(i=1; i<=n; i++){
			scanf("%d", &k);
			if(k>v.back()) v.push_back(k);
			else *lower_bound(v.begin(), v.end(), k)=k;
		}
		printf("%d\n", v.size()-1);
	}
}
