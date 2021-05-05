#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int n, i, d[2010];

int main(){
	scanf("%d", &n);
	v.push_back(0);
	for(i=n; i>=1; i--) scanf("%d", &d[i]);
	for(i=1; i<=n; i++){
		if(v.back()<d[i]) v.push_back(d[i]);
		else{
			auto t=lower_bound(v.begin(), v.end(), d[i]);
			*t=d[i];
		}
	}
	printf("%d", n-v.size()+1);
}
