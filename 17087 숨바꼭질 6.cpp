#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;

int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b, a%b);
}

int abs(int t){ return t>0?t:-t; }

int main(){
	int n, s, t, i;
	scanf("%d %d", &n, &s);
	for(i=0; i<n; i++){
		scanf("%d", &t);
		v.push_back(abs(t-s));
	}
	sort(v.begin(), v.end());
	if(n==1) printf("%d", v[0]);
	else{
		t=gcd(v[0], v[1]);
		for(i=2; i<v.size(); i++)
			t=gcd(t, v[i]);
		printf("%d", t);
	}
}
