#include<stdio.h>
#include<vector>
using namespace std;
vector<int> s;
int n, d[1000100];

void upd(int c, int a, int b, int idx, int t){
	if(idx<a||idx>b) return;
	s[c]+=t;
	if(a!=b){
		int m=(a+b)>>1;
		upd(c*2, a, m, idx, t);
		upd(c*2+1, m+1, b, idx, t);
	}
}

int find(int c, int t, int a, int b){
	if(a==b) return a;
	int m=(a+b)>>1;
	if(t<=s[c*2]) return find(c*2, t, a, m);
	else return find(c*2+1, t-s[c*2], m+1, b);
}

int main(){
	int n, a, b, c, i;
	scanf("%d", &n); s.resize(5000000);
	for(i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
		if(a&1){
			c=find(1, b, 1, 1e6);
			printf("%d\n", c);
			d[c]--; upd(1, 1, 1e6, c, -1);
		}
		else{
			scanf("%d", &c); d[b]+=c;
			upd(1, 1, 1e6, b, c);
		}
	}
}
