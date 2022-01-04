#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v;

int main(){
	int n, t, i;
	scanf("%d", &n);
	v.push_back(0);
	for(i=0; i<n; i++){
		scanf("%d", &t);
		if(v.back()<t) v.push_back(t);
		else *lower_bound(v.begin(), v.end(), t)=t;
	}
	printf("%d", v.size()-1);
}
