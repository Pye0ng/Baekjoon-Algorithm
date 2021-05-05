#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int n, p;

int lower_bound(int k){
	if(k<v[0]) return -1;
	else if(k>=v[p]) return p;
	else{
		for(int i=0; i<p; i++)
			if(v[i]<=k&&k<v[i+1]) return i;
	}
}

int main(){
	int n, k, i;
	scanf("%d", &n);
	p=n-1;
	for(i=0; i<n*n; i++){
		scanf("%d", &k);
		if(v.size()<p) v.push_back(k);
		else if(v.size()==p){
			v.push_back(k);
			sort(v.begin(), v.end());
		}
		else{
			int s=lower_bound(k);
			if(s!=-1){
				v.insert(v.begin()+s+1, k);
				v.erase(v.begin());
			}
		}
 	}
	printf("%d", v[0]);
}
