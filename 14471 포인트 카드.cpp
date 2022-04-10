#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int p, q;

int main(){
	int n, m, a, b, i;
	scanf("%d %d", &n, &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		if(a>=b) p++;
		else v.push_back((b-a)/2);
	}
	if(p<m-1){
		sort(v.begin(), v.end());
		for(i=0; i<m-p-1; i++) q+=v[i];
	}
	printf("%d", q);
}
