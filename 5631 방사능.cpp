#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int x[200200], y[200200];

int main(){
	int n, a, b, c, d, q, j, k, r1, r2, i, t=1;
	scanf("%d", &n); 
	while(n){
		vector<int> v1, v2;
		for(i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &q);
		for(i=0; i<n; i++){
			v1.push_back((a-x[i])*(a-x[i])+(b-y[i])*(b-y[i]));
			v2.push_back((c-x[i])*(c-x[i])+(d-y[i])*(d-y[i]));
		}
		sort(v1.begin(), v1.end()); sort(v2.begin(), v2.end());
		printf("Case %d:\n", t++);
		for(i=0; i<q; i++){
			scanf("%d %d", &r1, &r2);
			j=upper_bound(v1.begin(), v1.end(), r1*r1)-v1.begin();
			k=upper_bound(v2.begin(), v2.end(), r2*r2)-v2.begin();
			printf("%d\n", max(n-j-k, 0));
		}
		scanf("%d", &n);
	}
} 
