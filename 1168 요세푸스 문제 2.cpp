#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v;

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m);
	v.resize(n);
	for(i=0; i<n; i++) v[i]=i+1;
	int now=0;
	printf("<");
	while(v.size()!=1){
		now+=m-1;
		if(now>=v.size()) now%=v.size();
		printf("%d, ", v[now]);
		v.erase(v.begin()+now);
	}
	printf("%d>", v[0]);
}
