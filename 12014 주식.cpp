#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int t, n, k, p, i, j;
	scanf("%d", &t); 
	for(i=1; i<=t; i++){
		vector<int> v; v.push_back(0);
		scanf("%d %d", &n, &k);
		for(j=0; j<n; j++){
			scanf("%d", &p);
			if(p>v.back()) v.push_back(p);
			else *lower_bound(v.begin(), v.end(), p)=p;
		}
		printf("Case #%d\n%d\n", i, v.size()>k);
	}
}
