#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
vector<int> v;
set<int> s;
set<int>::iterator p;
int n, d[1000100];

int fd(int k){
	int s=0, e=v.size();
	while(e>s){
		int m=(s+e)/2;
		if(v[m]<k) s=m+1;
		else if(v[m]>k) e=m;
		else return m;
	}
}

int main(){
	int i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &d[i]);
		s.insert(d[i]);
	}
	int sz=s.size();
	for(i=0; i<sz; i++){
		p=s.begin();
		v.push_back(*p);
		s.erase(p);
	}
	for(i=0; i<n; i++) printf("%d ", fd(d[i]));
}
