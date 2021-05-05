#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v, t;

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		v.push_back(i);
		if(i>m) t.push_back(0);
		else t.push_back(1);
	}
	do{
		for(i=0; i<t.size(); i++)
			if(t[i]) printf("%d ", v[i]);
		printf("\n");
	}while(prev_permutation(t.begin(), t.end()));
}
